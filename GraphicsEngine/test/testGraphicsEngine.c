#include "GraphicsEngine.h"
#include "Vector2.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "Color.h"
#include "testGraphicsEngine.h"
#include <malloc.h>

char testBufferConstructor(){
	Buffer testbuffer1;
	Buffer testbuffer2;
	BufferConstructor(&testbuffer1, 2, 3);
	char* data = (char*)malloc(6*4);
	for (int i=0;i<6*4;i++){
		data[i]=0;
		testbuffer1.buffer[i]=0;
	}
	testbuffer2.buffer=data;
	testbuffer2.height=3;
	testbuffer2.width=2;
	if(testbuffer2.height!=testbuffer1.height){
		return 1;
	}
	if(testbuffer2.width!=testbuffer1.width){
		return 1;
	}
	for (int i=0;i<6*4;i++){
		if (testbuffer1.buffer[i]!=testbuffer2.buffer[i]){
			return 1;
		}
	}
	return 0;
}
char testBufferClear(){
	Buffer testbuffer1;
	Buffer testbuffer2;
	BufferConstructor(&testbuffer1, 2, 3);
	char* data = (char*)malloc(6*4);
	BufferClear(&testbuffer1,0,0,0);
	for (int i=0;i<6*4;i++){
		data[i]=0;
		if ((i+1)%4==0){
			data[i]=255;
		}
	}
	testbuffer2.buffer=data;
	testbuffer2.height=3;
	testbuffer2.width=2;
	if(testbuffer2.height!=testbuffer1.height){
		return 1;
	}
	if(testbuffer2.width!=testbuffer1.width){
		return 1;
	}
	for (int i=0;i<6*4;i++){
		if (testbuffer1.buffer[i]!=testbuffer2.buffer[i]){
			return 1;
		}
	}
	return 0;
}
char testBufferDrawObject(){
	Matrix3x3 testmatrix;
	setIdentity(&testmatrix);
	Buffer testbuffer;
	Buffer testbuffer1;
	testbuffer.height=2;
	testbuffer.width=2;
	testbuffer1.height=2;
	testbuffer1.width=2;
	char* data = (char*)malloc(16);
	const char data1[16]={0, 0, 0, 0, 0, 0, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0};
	testbuffer1.buffer=(char*)data1;
	char* pixels = (char*)malloc(16);
	for (int i=0;i<4*4;i++){
		data[i]=0;
		pixels[i]=255;
	}
	testbuffer.buffer=data;
	Texture texture;
	texture.height=2;
	texture.width=2;
	texture.pixels=pixels;
	VertexMesh test;
	CreateVertexBox(&test);
	BufferDrawObject(&testbuffer,testmatrix,&test,&texture);
	for (int i=0;i<4*4;i++){
		if (testbuffer.buffer[i]!=testbuffer1.buffer[i]){
			return 1;
		}
	}
	return 0;

}

int testGraphicsEngine()
{
	if(testBufferConstructor())
	{
		printf("testing BufferConstructor: ERROR\n");
		return 1;
	}
	printf("testing BufferConstructor: SUCCSESSFULL\n");
	
	if(testBufferClear())
	{
		printf("testing BufferClear: ERROR\n");
		return 1;
	}	
	printf("testing BufferClear: SUCCSESSFULL\n");
	
	if(testBufferDrawObject())
	{
		printf("testing BufferDrawObject: ERROR\n");
		return 1;
	}
	printf("testing BufferDrawObject: SUCCSESSFULL\n");
	
	return 0;
}
#pragma once
class ZynAddSubFx_Interface
{
public: 

	//���ò���
	virtual void setpramater(int iChannels,int iSampleRate) = 0;

	//����������Ч.
	virtual void setdryonly(bool value) = 0;

	//������Ч����
	virtual void changeeffect(int iIndex) = 0;

	//��������
	virtual bool put_pcm(char *pcm, int iSize) = 0;

};
extern "C" __declspec(dllexport) ZynAddSubFx_Interface *CreateInstance();

extern "C" __declspec(dllexport) void DestoryInstance(ZynAddSubFx_Interface *p);

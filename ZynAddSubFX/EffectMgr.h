/*
ZynAddSubFX - a software synthesizer

EffectMgr.h - Effect manager, an interface betwen the program and effects
Copyright (C) 2002-2005 Nasca Octavian Paul
Author: Nasca Octavian Paul

This program is free software; you can redistribute it and/or modify
it under the terms of version 2 of the GNU General Public License 
as published by the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License (version 2) for more details.

You should have received a copy of the GNU General Public License (version 2)
along with this program; if not, write to the Free Software Foundation,
Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA

*/

#ifndef EFFECTMGR_H
#define EFFECTMGR_H
#include "Effect.h"

#define DEF_AUDIO_VOL_STEP_CNT	6
#define DEF_AUDIO_LEFT_CHANNEL	0
#define DEF_AUDIO_RIGHT_CHANNEL	1
#define DEF_AUDIO_MAX_VOLUME	32767
#define DEF_AUDIO_MIN_VOLUME	(-32767)

class EffectMgr
{
public:
	//EffectMgr(int insertion_,pthread_mutex_t *mutex_);
	EffectMgr(int insertion_);
	~EffectMgr();
	/*
	void add2XML(XMLwrapper *xml);
	void getfromXML(XMLwrapper *xml);
	*/
	void defaults();

	//��ʹ����Ч
	void setdryonly(bool value);

	bool getdryonly() {return dryonly;	}

	//get the output(to speakers) volume of the systemeffect
	REALTYPE sysefxgetvolume();

	void cleanup();//cleanup the effect

	//����Ч��/*1:Reverb 2:Echo 3:Chorus 4:Phaser 5:Alienwah:6:Distorsion 7:EQ */
	void changeeffect(int nefx_);

	//�õ�Ч��
	int geteffect();
	void changepreset(unsigned char npreset);
	void changepreset_nolock(unsigned char npreset);
	unsigned char getpreset();
	
	//����Ч������
	void seteffectpar(int npar,unsigned char value);
	void seteffectpar_nolock(int npar,unsigned char value);//sets the effect par without thread lock
	
	//�õ�Ч������
	unsigned char geteffectpar(int npar);
	int insertion;//1 if the effect is connected as insertion effect
	
	REALTYPE *efxoutl,*efxoutr;

	//used by UI
	REALTYPE getEQfreqresponse(REALTYPE freq);

	FilterParams *filterpars;
	//REALTYPE *denormalkillbuf;

	//��������,�Գ������޵���������16������������˥��
	REALTYPE MixAudio(REALTYPE aSampleIn,REALTYPE aSampleOut,float* aVolPercent);

public:
	//���ø�����ʪ��ϵ�����ɵ�������
	void SetDryWetCoeff(float afDry, float afWet);

	//Apply the effect������FALSEʱ�޷�
	bool out(REALTYPE *smpsl,REALTYPE *smpsr);

private:
	int nefx;
	Effect *efx;
	//	pthread_mutex_t *mutex;
	bool dryonly;

	float m_fSetpValue[DEF_AUDIO_VOL_STEP_CNT];	//�����½��ٷֱȱ�
	float m_fVolPercent[2];	//����������ǰ�½�ֵ

private:
	float m_dryCoeff;		//����ϵ��
	float m_wetCoeff;		//ʪ��ϵ��
};
#endif




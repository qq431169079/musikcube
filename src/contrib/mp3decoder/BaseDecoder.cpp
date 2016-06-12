/*
Copyright (c) 2002 Tony Million

This software is provided 'as-is', without any express or 
implied warranty. In no event will the authors be held liable 
for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any 
purpose, including commercial applications, and to alter it 
and redistribute it freely, subject to the following 
restrictions:

1. The origin of this software must not be 
misrepresented; you must not claim that you wrote 
the original software. If you use this software in a 
product, an acknowledgment in the product 
documentation is required.

2. Altered source versions must be plainly marked as 
such, and must not be misrepresented as being the 
original software.

3. This notice may not be removed or altered from any 
source distribution.
*/

#include "stdafx.h"

#include <math.h>
#include "BaseDecoder.h"

const float CBaseDecoder::D[512] = 
{
	 0.000000000f, -0.000015259f, -0.000015259f, -0.000015259f,	-0.000015259f, -0.000015259f, -0.000015259f, -0.000030518f,
	-0.000030518f, -0.000030518f, -0.000030518f, -0.000045776f,	-0.000045776f, -0.000061035f, -0.000061035f, -0.000076294f,
	-0.000076294f, -0.000091553f, -0.000106812f, -0.000106812f,	-0.000122070f, -0.000137329f, -0.000152588f, -0.000167847f,
	-0.000198364f, -0.000213623f, -0.000244141f, -0.000259399f,	-0.000289917f, -0.000320435f, -0.000366211f, -0.000396729f,

	-0.000442505f, -0.000473022f, -0.000534058f, -0.000579834f,	-0.000625610f, -0.000686646f, -0.000747681f, -0.000808716f,
	-0.000885010f, -0.000961304f, -0.001037598f, -0.001113892f,	-0.001205444f, -0.001296997f, -0.001388550f, -0.001480103f,
	-0.001586914f, -0.001693726f, -0.001785278f, -0.001907349f,	-0.002014160f, -0.002120972f, -0.002243042f, -0.002349854f,
	-0.002456665f, -0.002578735f, -0.002685547f, -0.002792358f,	-0.002899170f, -0.002990723f, -0.003082275f, -0.003173828f,

	 0.003250122f,  0.003326416f,  0.003387451f,  0.003433228f,	 0.003463745f,  0.003479004f,  0.003479004f,  0.003463745f,
	 0.003417969f,  0.003372192f,  0.003280640f,  0.003173828f,	 0.003051758f,  0.002883911f,  0.002700806f,  0.002487183f,
	 0.002227783f,  0.001937866f,  0.001617432f,  0.001266479f,	 0.000869751f,  0.000442505f, -0.000030518f, -0.000549316f,
	-0.001098633f, -0.001693726f, -0.002334595f, -0.003005981f,	-0.003723145f, -0.004486084f, -0.005294800f, -0.006118774f,

	-0.007003784f, -0.007919312f, -0.008865356f, -0.009841919f,	-0.010848999f, -0.011886597f, -0.012939453f, -0.014022827f,
	-0.015121460f, -0.016235352f, -0.017349243f, -0.018463135f,	-0.019577026f, -0.020690918f, -0.021789551f, -0.022857666f,
	-0.023910522f, -0.024932861f, -0.025909424f, -0.026840210f,	-0.027725220f, -0.028533936f, -0.029281616f, -0.029937744f,
	-0.030532837f, -0.031005859f, -0.031387329f, -0.031661987f,	-0.031814575f, -0.031845093f, -0.031738281f, -0.031478882f,

	 0.031082153f,  0.030517578f,  0.029785156f,  0.028884888f,	 0.027801514f,  0.026535034f,  0.025085449f,  0.023422241f,
	 0.021575928f,  0.019531250f,  0.017257690f,  0.014801025f,	 0.012115479f,  0.009231567f,  0.006134033f,  0.002822876f,
	-0.000686646f, -0.004394531f, -0.008316040f, -0.012420654f,	-0.016708374f, -0.021179199f, -0.025817871f, -0.030609131f,
	-0.035552979f, -0.040634155f, -0.045837402f, -0.051132202f,	-0.056533813f, -0.061996460f, -0.067520142f, -0.073059082f,

	-0.078628540f, -0.084182739f, -0.089706421f, -0.095169067f,	-0.100540161f, -0.105819702f, -0.110946655f, -0.115921021f,
	-0.120697021f, -0.125259399f, -0.129562378f, -0.133590698f,	-0.137298584f, -0.140670776f, -0.143676758f, -0.146255493f,
	-0.148422241f, -0.150115967f, -0.151306152f, -0.151962280f,	-0.152069092f, -0.151596069f, -0.150497437f, -0.148773193f,
	-0.146362305f, -0.143264771f, -0.139450073f, -0.134887695f,	-0.129577637f, -0.123474121f, -0.116577148f, -0.108856201f,

	 0.100311279f,  0.090927124f,  0.080688477f,  0.069595337f,	 0.057617187f,  0.044784546f,  0.031082153f,  0.016510010f,
	 0.001068115f, -0.015228271f, -0.032379150f, -0.050354004f,	-0.069168091f, -0.088775635f, -0.109161377f, -0.130310059f,
	-0.152206421f, -0.174789429f, -0.198059082f, -0.221984863f,	-0.246505737f, -0.271591187f, -0.297210693f, -0.323318481f,
	-0.349868774f, -0.376800537f, -0.404083252f, -0.431655884f,	-0.459472656f, -0.487472534f, -0.515609741f, -0.543823242f,

	-0.572036743f, -0.600219727f, -0.628295898f, -0.656219482f,	-0.683914185f, -0.711318970f, -0.738372803f, -0.765029907f,
	-0.791213989f, -0.816864014f, -0.841949463f, -0.866363525f,	-0.890090942f, -0.913055420f, -0.935195923f, -0.956481934f,
	-0.976852417f, -0.996246338f, -1.014617920f, -1.031936646f,	-1.048156738f, -1.063217163f, -1.077117920f, -1.089782715f,
	-1.101211548f, -1.111373901f, -1.120223999f, -1.127746582f,	-1.133926392f, -1.138763428f, -1.142211914f, -1.144287109f,

	 1.144989014f,  1.144287109f,  1.142211914f,  1.138763428f,	 1.133926392f,  1.127746582f,  1.120223999f,  1.111373901f,
	 1.101211548f,  1.089782715f,  1.077117920f,  1.063217163f,	 1.048156738f,  1.031936646f,  1.014617920f,  0.996246338f,
	 0.976852417f,  0.956481934f,  0.935195923f,  0.913055420f,	 0.890090942f,  0.866363525f,  0.841949463f,  0.816864014f,
	 0.791213989f,  0.765029907f,  0.738372803f,  0.711318970f,	 0.683914185f,  0.656219482f,  0.628295898f,  0.600219727f,

	 0.572036743f,  0.543823242f,  0.515609741f,  0.487472534f,	 0.459472656f,  0.431655884f,  0.404083252f,  0.376800537f,
	 0.349868774f,  0.323318481f,  0.297210693f,  0.271591187f,	 0.246505737f,  0.221984863f,  0.198059082f,  0.174789429f,
	 0.152206421f,  0.130310059f,  0.109161377f,  0.088775635f,	 0.069168091f,  0.050354004f,  0.032379150f,  0.015228271f,
	-0.001068115f, -0.016510010f, -0.031082153f, -0.044784546f,	-0.057617187f, -0.069595337f, -0.080688477f, -0.090927124f,

	 0.100311279f,  0.108856201f,  0.116577148f,  0.123474121f,	 0.129577637f,  0.134887695f,  0.139450073f,  0.143264771f,
	 0.146362305f,  0.148773193f,  0.150497437f,  0.151596069f,	 0.152069092f,  0.151962280f,  0.151306152f,  0.150115967f,
	 0.148422241f,  0.146255493f,  0.143676758f,  0.140670776f,	 0.137298584f,  0.133590698f,  0.129562378f,  0.125259399f,
	 0.120697021f,  0.115921021f,  0.110946655f,  0.105819702f,	 0.100540161f,  0.095169067f,  0.089706421f,  0.084182739f,

	 0.078628540f,  0.073059082f,  0.067520142f,  0.061996460f,	 0.056533813f,  0.051132202f,  0.045837402f,  0.040634155f,
	 0.035552979f,  0.030609131f,  0.025817871f,  0.021179199f,	 0.016708374f,  0.012420654f,  0.008316040f,  0.004394531f,
	 0.000686646f, -0.002822876f, -0.006134033f, -0.009231567f,	-0.012115479f, -0.014801025f, -0.017257690f, -0.019531250f,
	-0.021575928f, -0.023422241f, -0.025085449f, -0.026535034f,	-0.027801514f, -0.028884888f, -0.029785156f, -0.030517578f,

	 0.031082153f,  0.031478882f,  0.031738281f,  0.031845093f,	 0.031814575f,  0.031661987f,  0.031387329f,  0.031005859f,
	 0.030532837f,  0.029937744f,  0.029281616f,  0.028533936f,	 0.027725220f,  0.026840210f,  0.025909424f,  0.024932861f,
	 0.023910522f,  0.022857666f,  0.021789551f,  0.020690918f,	 0.019577026f,  0.018463135f,  0.017349243f,  0.016235352f,
	 0.015121460f,  0.014022827f,  0.012939453f,  0.011886597f,	 0.010848999f,  0.009841919f,  0.008865356f,  0.007919312f,

	 0.007003784f,  0.006118774f,  0.005294800f,  0.004486084f,	 0.003723145f,  0.003005981f,  0.002334595f,  0.001693726f,
	 0.001098633f,  0.000549316f,  0.000030518f, -0.000442505f,	-0.000869751f, -0.001266479f, -0.001617432f, -0.001937866f,
	-0.002227783f, -0.002487183f, -0.002700806f, -0.002883911f,	-0.003051758f, -0.003173828f, -0.003280640f, -0.003372192f,
	-0.003417969f, -0.003463745f, -0.003479004f, -0.003479004f,	-0.003463745f, -0.003433228f, -0.003387451f, -0.003326416f,

	 0.003250122f,  0.003173828f,  0.003082275f,  0.002990723f,	 0.002899170f,  0.002792358f,  0.002685547f,  0.002578735f,
	 0.002456665f,  0.002349854f,  0.002243042f,  0.002120972f,	 0.002014160f,  0.001907349f,  0.001785278f,  0.001693726f,
	 0.001586914f,  0.001480103f,  0.001388550f,  0.001296997f,	 0.001205444f,  0.001113892f,  0.001037598f,  0.000961304f,
	 0.000885010f,  0.000808716f,  0.000747681f,  0.000686646f,	 0.000625610f,  0.000579834f,  0.000534058f,  0.000473022f,

	 0.000442505f,  0.000396729f,  0.000366211f,  0.000320435f,	 0.000289917f,  0.000259399f,  0.000244141f,  0.000213623f,
	 0.000198364f,  0.000167847f,  0.000152588f,  0.000137329f,	 0.000122070f,  0.000106812f,  0.000106812f,  0.000091553f,
	 0.000076294f,  0.000076294f,  0.000061035f,  0.000061035f,	 0.000045776f,  0.000045776f,  0.000030518f,  0.000030518f,
	 0.000030518f,  0.000030518f,  0.000015259f,  0.000015259f,	 0.000015259f,  0.000015259f,  0.000015259f,  0.000015259f
};


CBaseDecoder::CBaseDecoder()
{
	int i,j;
	float t16[16][16], t8[8][8];

	/* assign and clear the subband synthesis V buffer */

	for(i = 0; i < 2; i++)
		for(j = 0; j < 1024; j++)
			V[i][j] = (float)0.0f;

	/* create the 16 matrixes */

	for(i = 0; i < 16; i++) 
	{
		for(j = 0; j < 16; j++) 
		{
			A16[i][j] = (float)cos((2*j+1)*i*PI/32);
			if(i == j || j == (i + 1))
				G16[i][j] = 1.0f;
			else
				G16[i][j] = 0.0f;

			if(i == j)
				H16[i][j] = 1.0f/(2.0f*(float)cos((2*i+1)*PI/64));
			else
				H16[i][j] = 0.0;
		}
	}

	/* create the 8 matrixes */

	for(i = 0; i < 8; i++) 
	{
		for(j = 0; j < 8; j++) 
		{
			A8[i][j] = (float)cos((2*j+1)*i*PI/16);
			if(i == j || j == (i + 1))
				G8[i][j] = 1.0f;
			else
				G8[i][j] = 0.0f;

			if(i == j)
				H8[i][j] = 1.0f/(2.0f*(float)cos((2*i+1)*PI/32));
			else
				H8[i][j] = 0.0f;
		}
	}

	/* generate the B matrixes */

	MultiplyMatrix16(A16, H16, t16);
	MultiplyMatrix16(G16, t16, B16);

	MultiplyMatrix8(A8, H8, t8);
	MultiplyMatrix8(G8, t8, B8);

	int a, o = 0;

	for (j = 0; j < 32; j++) 
	{
		a = j;

		for(i = 0; i < 4; i++) 
		{
			DTable[o] = D[a];
			o++;

			DTable[o] = D[a+32];
			o++;

			DTable[o] = D[a+64];
			o++;

			DTable[o] = D[a+96];
			o++;

			a+=128;
		}
	}

	Vpointer[0] = 64;
	Vpointer[1] = 64;
}

CBaseDecoder::~CBaseDecoder()
{

}

bool CBaseDecoder::PerformSynthesis(float *InputFreq, float *ToHere, int Channel, int step)
{
	if(Channel)
		ToHere ++;

	/* We have 18 time-vectors of 32 subband magnitudes each. For every
	   vector of 32 magnitudes, the subband synthesis generates 32
	   PCM samples, so the result of 18 of these is 18*32=576 samples.
	 */

	/* advance the buffer position */
	Vpointer[Channel] = (Vpointer[Channel] - 64) & 0x3ff;

	IDCT(InputFreq, &V[ Channel ][ Vpointer[Channel] ]);

	/* 32*16=512 mac's */

	Window(Channel, ToHere, step);

	return(true);
}

void __forceinline CBaseDecoder::IDCT(float *input, float *out)
{
    float odd[16];
    float t[32];

    float s1, s2;

    int i;
	int offset1 = 0;
	int offset = 0;
	int ti = 0; // table index

    float even[16], ee[8], eo[8];

    /* input butterflies - level 1 */
    /* 32 adds */

	even[0]		= input[0]	 + input[31];
	even[1]		= input[1]	 + input[30];
	even[2]		= input[2]	 + input[29];
	even[3]		= input[3]	 + input[28];
	even[4]		= input[4]	 + input[27];
	even[5]		= input[5]	 + input[26];
	even[6]		= input[6]	 + input[25];
	even[7]		= input[7]	 + input[24];
	even[8]		= input[8]	 + input[23];
	even[9]		= input[9]	 + input[22];
	even[10]	= input[10] + input[21];
	even[11]	= input[11] + input[20];
	even[12]	= input[12] + input[19];
	even[13]	= input[13] + input[18];
	even[14]	= input[14] + input[17];
	even[15]	= input[15] + input[16];

	odd[0]		= input[0]	 - input[31];
	odd[1]		= input[1]	 - input[30];
	odd[2]		= input[2]	 - input[29];
	odd[3]		= input[3]	 - input[28];
	odd[4]		= input[4]	 - input[27];
	odd[5]		= input[5]	 - input[26];
	odd[6]		= input[6]	 - input[25];
	odd[7]		= input[7]	 - input[24];
	odd[8]		= input[8]	 - input[23];
	odd[9]		= input[9]	 - input[22];
	odd[10]		= input[10] - input[21];
	odd[11]		= input[11] - input[20];
	odd[12]		= input[12] - input[19];
	odd[13]		= input[13] - input[18];
	odd[14]		= input[14] - input[17];
	odd[15]		= input[15] - input[16];

    /* input butterflies - level 2 */
    /* 16 adds */

	ee[0]	= even[0] + even[15];
	ee[1]	= even[1] + even[14];
	ee[2]	= even[2] + even[13];
	ee[3]	= even[3] + even[12];
	ee[4]	= even[4] + even[11];
	ee[5]	= even[5] + even[10];
	ee[6]	= even[6] + even[9];
	ee[7]	= even[7] + even[8];

	eo[0]	= even[0] - even[15];
	eo[1]	= even[1] - even[14];
	eo[2]	= even[2] - even[13];
	eo[3]	= even[3] - even[12];
	eo[4]	= even[4] - even[11];
	eo[5]	= even[5] - even[10];
	eo[6]	= even[6] - even[9];
	eo[7]	= even[7] - even[8];


    /* multiply the even_even vector (ee) with the ee matrix (A8) */
    /* multiply the even_odd vector (eo) with the eo matrix (B8) */
    /* 128 muls, 128 adds */

	i=8;

    do
	{
		s1  = A8[ti][0]	* ee[0];
		s1 += A8[ti][1]	* ee[1];
		s1 += A8[ti][2]	* ee[2];
		s1 += A8[ti][3]	* ee[3];
		s1 += A8[ti][4]	* ee[4];
		s1 += A8[ti][5]	* ee[5];
		s1 += A8[ti][6]	* ee[6];
		s1 += A8[ti][7]	* ee[7];

		s2  = B8[ti][0]	* eo[0];
		s2 += B8[ti][1]	* eo[1];
		s2 += B8[ti][2]	* eo[2];
		s2 += B8[ti][3]	* eo[3];
		s2 += B8[ti][4]	* eo[4];
		s2 += B8[ti][5]	* eo[5];
		s2 += B8[ti][6]	* eo[6];
		s2 += B8[ti][7]	* eo[7];

		t[offset1]		= s1;
		t[offset1+2]	= s2;

		offset1 += 4;
		ti++;
	} while(--i);


	/* multiply the odd vector (odd) with the odd matrix (B16) */
    /* 256 muls, 256 adds */

	i = 16;
	ti = 0;

	do
	{
		s1  = B16[ti][0]	* odd[0];
		s1 += B16[ti][1]	* odd[1];
		s1 += B16[ti][2]	* odd[2];
		s1 += B16[ti][3]	* odd[3];
		s1 += B16[ti][4]	* odd[4];
		s1 += B16[ti][5]	* odd[5];
		s1 += B16[ti][6]	* odd[6];
		s1 += B16[ti][7]	* odd[7];
		s1 += B16[ti][8]	* odd[8];
		s1 += B16[ti][9]	* odd[9];
		s1 += B16[ti][10]	* odd[10];
		s1 += B16[ti][11]	* odd[11];
		s1 += B16[ti][12]	* odd[12];
		s1 += B16[ti][13]	* odd[13];
		s1 += B16[ti][14]	* odd[14];
		s1 += B16[ti][15]	* odd[15];

		t[offset+1] = s1;

		offset += 2;
		ti++;
    } while(--i);

    /* the output vector t now is expanded to 64 values using the
       symmetric property of the cosinus function */

	i = 16;
	ti = 0;

    do
	{
		out[ti]		=  t[ti+16];
		out[ti+17]	= -t[31-ti];
		out[ti+32]	= -t[16-ti];
		out[ti+48]	= -t[ti];

		ti++;

    } while(--i);

    out[16] = 0.0;
}

void __forceinline CBaseDecoder::Window(int ch, float *S, int step)
{
    int j, k;
    register float sum;

	//int a = 0;

    /* calculate 32 samples. each sample is the sum of 16 terms */
    
    /*     15          */
    /* Sj = E W((j*16)+i) */
    /*    i=0          */


	k = Vpointer[ch];
	float * TV = V[ch];
	float * DT = DTable;

    for(j = 0; j < 32; j++) 
	{
		sum  = DT[0x0] * TV[k];
		k = (k + 96) & 0x3ff;
		sum += DT[0x1] * TV[k];
		k = (k + 32) & 0x3ff; 

		sum += DT[0x2] * TV[k];
		k = (k + 96) & 0x3ff;
		sum += DT[0x3] * TV[k];
		k = (k + 32) & 0x3ff; 

		sum += DT[0x4] * TV[k];
		k = (k + 96) & 0x3ff;
		sum += DT[0x5] * TV[k];
		k = (k + 32) & 0x3ff; 

		sum += DT[0x6] * TV[k];
		k = (k + 96) & 0x3ff;
		sum += DT[0x7] * TV[k];
		k = (k + 32) & 0x3ff; 

		sum += DT[0x8] * TV[k];
		k = (k + 96) & 0x3ff;
		sum += DT[0x9] * TV[k];
		k = (k + 32) & 0x3ff; 

		sum += DT[0xA] * TV[k];
		k = (k + 96) & 0x3ff;
		sum += DT[0xB] * TV[k];
		k = (k + 32) & 0x3ff; 

		sum += DT[0xC] * TV[k];
		k = (k + 96) & 0x3ff;
		sum += DT[0xD] * TV[k];
		k = (k + 32) & 0x3ff; 

		sum += DT[0xE] * TV[k];
		k = (k + 96) & 0x3ff;
		sum += DT[0xF] * TV[k];
		k = (k + 32) & 0x3ff; 

		DT += 16;


		if( sum < -1.0 )
			sum = -1.0;
		else if( sum > 1.0 )
			sum = 1.0;
		*S = sum;

		S+=step;
		k++;

	}
}
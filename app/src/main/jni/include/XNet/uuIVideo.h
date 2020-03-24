#ifndef __UU_IVIDEO_H
#define __UU_IVIDEO_H

#include "uuVideo_Export.h"
#include "VIDEO_Header.h"


#if WIN32
#include "uuDefine.h"
#include "video.h"
#else

//���Ի���Ƶ�⣬������ʹ��VIDEO֮ǰ����
VIDEO_API int VIDEO_Init();

//��ֹ��Ƶ�⣬������ʹ����VIDEO֮�����
VIDEO_API void VIDEO_Terminate(void);

enum uuVideoCodecType 
{
	VIDEO_CODEC_H264 = 4,
	VIDEO_CODEC_Hardware
};

enum uuVideoOrigiDataType
{
	VO_DT_H264		= 0x0,
	VO_DT_RGBA_48	= 0x1,
	VO_DT_YUV 		= 0x32315659
};

enum VideoRotationMode {
  kRotateNone = 0,
  kRotate90 = 90,
  kRotate180 = 180,
  kRotate270 = 270,
};


class VIDEO_API VIDEO_Image
{
public:
	VIDEO_Image(void){};
	virtual~VIDEO_Image(void){};
public:
	virtual void AddRef(void)=0;
	virtual void Release(void)=0;
	virtual void*GetData(void)=0;
	virtual int GetDataLen(void)=0;
	virtual int GetWidth(void)=0;
	virtual int GetHeight(void)=0;
	virtual int GetFrameRate(void)=0;

	virtual bool GetIsH264Data(void)=0;
	virtual bool GetIsKeyFrame(void)=0;
	virtual bool GetIsBackCamera(void)=0;
	virtual VideoRotationMode GetFrameRotation(void)=0;

	static VIDEO_Image*Create(unsigned char*pData,int nLen,int nWidth,int nHeight,int nFrameRate=30);
};

#endif


typedef struct PACKET
{
	PACKET(char*pPacketData,int nPacketSize)
//		:m_pPacketData(pPacketData)
//		,m_nPacketSize(nPacketSize)
	{
		m_pPacketData = new char[nPacketSize];
		m_nPacketSize = nPacketSize;
		memcpy(m_pPacketData,(char*)pPacketData,nPacketSize);
	}
	~PACKET() 
	{
        if (m_pPacketData != NULL) {
            delete[] (char *)m_pPacketData;
            m_pPacketData = NULL;
            m_nPacketSize = 0;
        }
    }
	char*	m_pPacketData;
	int		m_nPacketSize;
}PACKET,*PPACKET;


class VIDEO_ICapChanCallback
{
public:
	VIDEO_ICapChanCallback(void){};
	virtual~VIDEO_ICapChanCallback(void){};
public:
	virtual void OnVIDEO_CapChanCallback(unsigned char*pData,int nLen,bool& bKeyFrame,int nWidth,int nHeight,int nHeaderLen)=0;
};


#ifndef Surface
	#if WIN32
		#define Surface HWND
	#else if ANDROID
		#define Surface void*
	#endif
#endif

//��Ƶ�ɼ���֧��ѹ������֡�ķ�ʽ�����
class VIDEO_IVideoCapChan
{
public:
	/******************************************************************************
	* Init
	* ��  ������ʼ��
	* ����ֵ����
	*******************************************************************************/
	virtual int  Init(int iCapType = 1) = 0;

	/******************************************************************************
	* Destory
	* ��  ��: ��ֹ
	* ����ֵ����
	*******************************************************************************/
	virtual void  Destory() = 0;


	/******************************************************************************
	* Open
	*������  ��Ƶ�ɼ�
	*������  
			 nCameraIndex  �豸ID ǰ������ͷ  ��������ͷ��������ֵ��Ч��
			 nWidth        ��Ƶ���������������������õĲ�������ͷ��֧�֣���ѡ��֧�ֵ���С������
			 nHeight 	   ��Ƶ�ߣ�ͬ�ϲ�����
			 nBitrate      ��Ƶ����
			 nFrameRate    ��Ƶ�ɼ���֡����Ĭ��15֡��
	*����ֵ���ɹ�����0
	         ʧ�ܷ���-1
	*****************************************************************************/
	virtual int  Open(int nCameraIndex,int& nWidth,int& nHeight,int nBitrate,int nFrameRate=30) = 0;


	/******************************************************************************
	* Close
	* ��  �����ر���Ƶ�ɼ�
	* ����ֵ����
	*******************************************************************************/
	virtual void Close() = 0;

	virtual void SetPreview(Surface sView) = 0;

	//virtual void SetCameraID(int nID) = 0;

	//virtual void SetVideoCaptureSize(int nWidth, int nHeight) = 0;

	//virtual void SetFrameRate(int nFrameRate) = 0;

	//virtual void SetBitrate(int nBitrate) = 0;

	virtual int RegisterCallback(VIDEO_ICapChanCallback* pCapChanCallback) = 0;

	virtual int DeRegisterCallback() = 0;

	virtual void ForceKeyFrame() = 0;


	//add by taor 2015-06-04
#ifdef WIN32	
	virtual void GetVideoParameterInfo(VIDEO_RESOLUTION_MAP &mapResolution, int &nFrameRate, int &nBitRate, int &nWidth, int &nHeight) = 0;
#endif // WIN32
	//end add by taor 201-06-04

	virtual int SwitchCamera() = 0;


};

VIDEO_IVideoCapChan* CreateVideoCapChan();


class VIDEO_IPlayChanCallback
{
public:
	VIDEO_IPlayChanCallback(void){};
	virtual~VIDEO_IPlayChanCallback(void){};
public:
	virtual void OnVIDEO_PlayChanCallback(unsigned char*pData,int nLen,bool bKeyFrame,int nWidth,int nHeight,int nHeaderLen)=0;
};

class VIDEO_IVideoPlayChan
{
public:
	VIDEO_IVideoPlayChan(void){};
	virtual~VIDEO_IVideoPlayChan(void){};

public:
	virtual int Init() = 0;
	virtual void Destory() = 0;

	virtual int Open() = 0;
	virtual void Close() = 0;

	virtual void PushPacket(unsigned char*pData,int nLen) = 0;

	virtual int SetDisplay(Surface sView) = 0;
	virtual int ResetDisplay(Surface sView) = 0;
	virtual void SetVideoID(int nVideoID) = 0;
};

VIDEO_IVideoPlayChan* CreateVideoPlayChan();





#endif


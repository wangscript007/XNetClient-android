#ifndef __UU_DEFINE_H_
#define __UU_DEFINE_H_

/*
���屾�������õ��ĳ���
*/

#include <string>
#include <map>

#include <assert.h>

using namespace std;


#define  LOCAL_MCUPort  5566
#define  REMOTE_MCUPort 5566

#ifndef YES
#define YES 1
#define NO  0
#endif

/*
typedef enum {
    CS_CONNECTING=0,		//��������
    CS_FAILED,				//�޷�����
    CS_CONNECTED,			//�Ѿ�����
    CS_DISCONNECTED,		//�Ͽ�����
    CS_BUSY,				//����æ(�ѶϿ�������)
    CS_RECONNECTED,			//�����ɹ�
    CS_IDLE,				//����
    CS_RESTARTED,			//���������ˡ����ӶϿ��ˣ������������������ˣ����ǻ���һ�������ӡ�
    CS_LOGINED,             //��½�������ɹ�
    CS_LOGINFAILED,         //��½������ʧ��
    CS_LOGOUT         //�˳�������
} CONNECT_NET_STATUS;
*/

typedef enum {
    MTG_CREAT=0,		//��������
    MTG_JOIN,
    MTG_EXIT,
    MTG_DESTROY
} MTG_CMD;

typedef enum {
    MTG_Common=0,        //��������
    MTG_MultIntercom,
  
} MTG_TYPE;

typedef enum
{
    AUDIO_SEND_ENABLE=0,    //���Է���
    AUDIO_SEND_DISABLE,     //���ܷ���
    AUDIO_SEND_SENDING         //���ڷ���
    
} AUDIO_SEND_STATUS;

typedef struct _CLIENTUSERINFOLIST
{
    _CLIENTUSERINFOLIST():strUserName("")
    ,strNickName("")
    ,strHeadUrl("")
    ,ulLatitude(0)
    ,ulLongitude(0)
    ,ulUserId(0)
    ,ulUserAudioID(0)
    ,uiVideoCanSee(0)
    ,ulMtgTime("")
    {}
    std::string   strUserName;
    std::string strHeadUrl;
    std::string strNickName;
    double ulLatitude;
    double ulLongitude;
    std::string ulMtgTime;
	unsigned long ulUserId;
	unsigned long ulUserAudioID;
	unsigned int  uiVideoCanSee;
	std::string   strLocalIP;
	std::string   strNATIP;
}CLIENTUSERINFOLIST;

typedef std::map<unsigned long, CLIENTUSERINFOLIST> CLIENTUSERINFOLIST_MAP;

//#define LOGI printf

unsigned long XGetTimestamp(void);

#endif

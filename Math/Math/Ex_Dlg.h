#pragma once

#include "stdafx.h"
#include "afxwin.h"
// CEx_Dlg �Ի���

class CEx_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(CEx_Dlg)

public:
	CEx_Dlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CEx_Dlg();

	virtual void OnFinalRelease();

// �Ի�������
	enum { IDD = IDD_Excesize };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:
	
	CString m_val;
	afx_msg void OnBnClickedButton1();
	CString strop[3];//��¼�����
	int count = 0,count1=0;//count��¼���������,count1��¼��ϰ�����
	//int m_Sub;
	int result;
	int sign=0;
	int m_Score[10];//��¼ÿ����ϰ�ߵ÷֣�������ֱ����������飬���ǳ��������ʼֵ�趨��DDX_Textת��
	int m_score;//�ؼ�������¼�÷�
	int count2=0;//��¼��ϰ�߸�����������ʮ��
	void Checkequal(int sub, CString m_sub);
	CEdit M_SUB;
	int m_sec;
	int m_minute;
	CString grade[20];//����һ����ϰ20��
	void Timer();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedButton3();
	CString m_Sub;
	int Highest;
	CString t_name[20];//��¼��߷���ϰ������
};

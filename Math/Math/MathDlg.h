
// MathDlg.h : ͷ�ļ�
//
#include "stdafx.h"
#include "Ex_Dlg.h"
#pragma once


// CMathDlg �Ի���
class CMathDlg : public CDialogEx
{
	// ����
public:

	CMathDlg(CWnd* pParent = NULL);	// ��׼���캯��

	// �Ի�������
	enum { IDD = IDD_MATH_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


	// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedBegin();
	CString m_name;
	//CString strctrl;
	//int Sub;
	CEx_Dlg dlg1;//����ȫ�֣�����������Ҫ�õ�ͬһ���Ի������
	int m_Minute;
	//CWnd m_font;
	afx_msg void OnBnClickedButton2();
	//��Ӹ��ؼ�������������������ʾ����m_name
};

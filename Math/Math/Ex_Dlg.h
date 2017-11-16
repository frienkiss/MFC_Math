#pragma once

#include "stdafx.h"
#include "afxwin.h"
// CEx_Dlg 对话框

class CEx_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(CEx_Dlg)

public:
	CEx_Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CEx_Dlg();

	virtual void OnFinalRelease();

// 对话框数据
	enum { IDD = IDD_Excesize };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:
	
	CString m_val;
	afx_msg void OnBnClickedButton1();
	CString strop[3];//记录运算符
	int count = 0,count1=0;//count记录运算符个数,count1记录练习题个数
	//int m_Sub;
	int result;
	int sign=0;
	int m_Score[10];//记录每个练习者得分，本来想直接用这个数组，但是出错，数组初始值设定和DDX_Text转换
	int m_score;//控件变量记录得分
	int count2=0;//记录练习者个数，上限是十个
	void Checkequal(int sub, CString m_sub);
	CEdit M_SUB;
	int m_sec;
	int m_minute;
	CString grade[20];//上限一次练习20题
	void Timer();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedButton3();
	CString m_Sub;
	int Highest;
	CString t_name[20];//记录最高分练习者名字
};

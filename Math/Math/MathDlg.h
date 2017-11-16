
// MathDlg.h : 头文件
//
#include "stdafx.h"
#include "Ex_Dlg.h"
#pragma once


// CMathDlg 对话框
class CMathDlg : public CDialogEx
{
	// 构造
public:

	CMathDlg(CWnd* pParent = NULL);	// 标准构造函数

	// 对话框数据
	enum { IDD = IDD_MATH_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


	// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
	CEx_Dlg dlg1;//定义全局，有两个函数要用到同一个对话框对象
	int m_Minute;
	//CWnd m_font;
	afx_msg void OnBnClickedButton2();
	//添加个控件变量，变量分数大，显示变量m_name
};

#pragma once


// Ex_Grade 对话框

class Ex_Grade : public CDialogEx
{
	DECLARE_DYNAMIC(Ex_Grade)

public:
	Ex_Grade(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Ex_Grade();

	virtual void OnFinalRelease();

// 对话框数据
	enum { IDD = IDD_Grade };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:
	CString m_grade;
	afx_msg void OnEnChangeEdit1();
};

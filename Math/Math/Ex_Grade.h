#pragma once


// Ex_Grade �Ի���

class Ex_Grade : public CDialogEx
{
	DECLARE_DYNAMIC(Ex_Grade)

public:
	Ex_Grade(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Ex_Grade();

	virtual void OnFinalRelease();

// �Ի�������
	enum { IDD = IDD_Grade };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:
	CString m_grade;
	afx_msg void OnEnChangeEdit1();
};

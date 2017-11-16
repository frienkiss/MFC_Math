// Ex_Grade.cpp : 实现文件
//

#include "stdafx.h"
#include "Math.h"
#include "Ex_Grade.h"
#include "afxdialogex.h"


// Ex_Grade 对话框

IMPLEMENT_DYNAMIC(Ex_Grade, CDialogEx)

Ex_Grade::Ex_Grade(CWnd* pParent /*=NULL*/)
	: CDialogEx(Ex_Grade::IDD, pParent)
	, m_grade(_T(""))
{

	EnableAutomation();
	
}

Ex_Grade::~Ex_Grade()
{
}

void Ex_Grade::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。  基类将自动
	// 删除该对象。  在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CDialogEx::OnFinalRelease();
}

void Ex_Grade::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_grade);
}


BEGIN_MESSAGE_MAP(Ex_Grade, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &Ex_Grade::OnEnChangeEdit1)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(Ex_Grade, CDialogEx)
END_DISPATCH_MAP()

// 注意: 我们添加 IID_IEx_Grade 支持
//  以支持来自 VBA 的类型安全绑定。  此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {AB5AA6C4-3788-47BA-8C91-7AADE3AFDCAD}
static const IID IID_IEx_Grade =
{ 0xAB5AA6C4, 0x3788, 0x47BA, { 0x8C, 0x91, 0x7A, 0xAD, 0xE3, 0xAF, 0xDC, 0xAD } };

BEGIN_INTERFACE_MAP(Ex_Grade, CDialogEx)
	INTERFACE_PART(Ex_Grade, IID_IEx_Grade, Dispatch)
END_INTERFACE_MAP()


// Ex_Grade 消息处理程序


void Ex_Grade::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

// Ex_Grade.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Math.h"
#include "Ex_Grade.h"
#include "afxdialogex.h"


// Ex_Grade �Ի���

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
	// �ͷ��˶��Զ�����������һ�����ú󣬽�����
	// OnFinalRelease��  ���ཫ�Զ�
	// ɾ���ö���  �ڵ��øû���֮ǰ�����������
	// ��������ĸ���������롣

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

// ע��: ������� IID_IEx_Grade ֧��
//  ��֧������ VBA �����Ͱ�ȫ�󶨡�  �� IID ����ͬ���ӵ� .IDL �ļ��е�
//  ���Ƚӿڵ� GUID ƥ�䡣

// {AB5AA6C4-3788-47BA-8C91-7AADE3AFDCAD}
static const IID IID_IEx_Grade =
{ 0xAB5AA6C4, 0x3788, 0x47BA, { 0x8C, 0x91, 0x7A, 0xAD, 0xE3, 0xAF, 0xDC, 0xAD } };

BEGIN_INTERFACE_MAP(Ex_Grade, CDialogEx)
	INTERFACE_PART(Ex_Grade, IID_IEx_Grade, Dispatch)
END_INTERFACE_MAP()


// Ex_Grade ��Ϣ�������


void Ex_Grade::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

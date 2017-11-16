// Ex_Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Math.h"
#include "Ex_Dlg.h"
#include "Ex_Grade.h"
#include "afxdialogex.h"
//#include "MathDlg.h"


// CEx_Dlg �Ի���

IMPLEMENT_DYNAMIC(CEx_Dlg, CDialogEx)

CEx_Dlg::CEx_Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CEx_Dlg::IDD, pParent)
	, m_val(_T(""))
	, m_score(NULL)//nullԤ������0
	, m_sec(0)
	, m_minute(0)
	, m_Sub(_T(""))
{

	EnableAutomation();
	//SetTimer(1, 1000, NULL);
	//SetDlgItemText(IDC_EDIT5, L" ");
	//UpdateData(false);//���
	//Timer();

}

CEx_Dlg::~CEx_Dlg()
{
}

void CEx_Dlg::OnFinalRelease()
{
	// �ͷ��˶��Զ�����������һ�����ú󣬽�����
	// OnFinalRelease��  ���ཫ�Զ�
	// ɾ���ö���  �ڵ��øû���֮ǰ�����������
	// ��������ĸ���������롣

	CDialogEx::OnFinalRelease();
}

void CEx_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT4, m_val);
	//DDX_Text(pDX, IDC_EDIT5, m_Sub);
	DDX_Text(pDX, IDC_EDIT2, m_score);
	DDX_Control(pDX, IDC_EDIT5, M_SUB);
	DDX_Text(pDX, IDC_EDIT1, m_sec);
	DDV_MinMaxInt(pDX, m_sec, -1, 59);
	DDX_Text(pDX, IDC_EDIT3, m_minute);
	//Timer();
	DDX_Text(pDX, IDC_EDIT5, m_Sub);
}


BEGIN_MESSAGE_MAP(CEx_Dlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CEx_Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CEx_Dlg::OnBnClickedButton2)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON3, &CEx_Dlg::OnBnClickedButton3)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CEx_Dlg, CDialogEx)
END_DISPATCH_MAP()

// ע��: ������� IID_IEx_Dlg ֧��
//  ��֧������ VBA �����Ͱ�ȫ�󶨡�  �� IID ����ͬ���ӵ� .IDL �ļ��е�
//  ���Ƚӿڵ� GUID ƥ�䡣

// {F8F23BF7-9033-4ACF-8D63-F7EDE0A81516}
static const IID IID_IEx_Dlg =
{ 0xF8F23BF7, 0x9033, 0x4ACF, { 0x8D, 0x63, 0xF7, 0xED, 0xE0, 0xA8, 0x15, 0x16 } };

BEGIN_INTERFACE_MAP(CEx_Dlg, CDialogEx)
	INTERFACE_PART(CEx_Dlg, IID_IEx_Dlg, Dispatch)
END_INTERFACE_MAP()


// CEx_Dlg ��Ϣ�������

//��ʼ��ϰ
void CEx_Dlg::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	/*CString m3;
	m3.Format(L"%d", result);
	MessageBox(m3);//����result�ǲ��Ǵ�������ȷ��ֵ*/
	//Timer();
	//SetTimer(1, 1000, NULL);
	Ex_Grade gravalue;//�ɼ�
	CString pan;
	
	UpdateData(true);
	
	if (m_Sub ==""){
		MessageBox(L"�������Ϊ�գ�");
		return;
	}
	
		
		Checkequal(result, m_Sub);
		CString str, strk1, strk2;
		//strk1=L"=";//�����±�����¼=
		
		grade[count1] = m_val + +L"="+m_Sub;
		count1++;
		//m_Sub = NULL;
		//M_SUB.SetWindowTextW(L"FDS");
		//M_SUB = NULL;
		//SetDlgItemTextW(IDC_EDIT5, NULL);//ˢ�±༭��Ϊ�հף��Ա���д����
		
		
		
	
		UpdateData(false);

		//M_SUB.SetSel(0, -1);
		//M_SUB.ReplaceSel(L" ");
		int k1 = rand() % 100 + 1;
		int k2 = rand() % 100 + 1;
		
		//result = k1 + k2;



		int r;//��һ�������ϲ������λ����r�����ڶ���û�м�¼�������




		int k = rand() % count;//����0~count-1�������������ѡ�������
		
		if (strop[k] == "+"){
			r = 0;
		//	strop[k] = "+";//��һ�ν���ʱstrop[k]ֵΪ"+",����ж�����ʧЧ��
		}
		if (strop[k] == "-"){
			r = 1;
			//strop[k] = "-";
		}
		if (strop[k] == "*"){
			r = 2;//
			//strop[k] = "*";
		}
		switch (r){
		case 0:
			result = k1 + k2; break;
		case 1:{
				   if (k1 < k2){
					   int temp;
					   temp = k1; k1 = k2; k2 = temp;
				   }
				   result = k1 - k2; break;

		}//��֤Сѧ�����㲻���ָ���
			
		case 2:
			result = k1*k2; break;

		}
	
		strk1.Format(L"%d", k1);
		strk2.Format(L"%d", k2);
		str = strk1 + strop[k] + strk2;
		UpdateData(true);
		m_val = str;


		strk1.Format(L"%d", result);
		strk2 = "=";
		grade[count1] = str + strk2 + strk1;
		
		count1++;
		if (count1 > 20){
			MessageBox(L"�����Ѿ��ﵽ���ޣ�����������´��⣡");
			OnCancel();
		}
		//strk2.Format(L"%d", m_score);//�÷֣��ж�result��m_Sub

		/*CString m1, m2;
		m1.Format(L"%d", Sub);
		m2.Format(L"%d", m_Sub);
		MessageBox(m1);//SubΪxiaһ������ʽ��ֵ
		MessageBox(m2);*/



		//m_score++;
		//InvalidateRect();
	
		
		UpdateData(FALSE);
		SetDlgItemText(IDC_EDIT5, L" ");
		

		
	
		
	
	

	

	/*UpdateData(true);
	m_val = str;
	UpdateData(false);*/


}


//�Ʒ�
void CEx_Dlg::Checkequal(int sub,CString m_sub)
{
	int m;
	m = _ttoi(m_sub);//Cstring->int
	if (sub == m)
		m_score++;

}


/*void CEx_Dlg::Timer()
{
	UpdateData(true);

	while (m_minute != -1)
	{
		m_sec--;
		if (m_minute == 0 && m_sec == 0){
			MessageBox(L"��ϰʱ�������");
			OnCancel();

		}
		if (m_sec = -1){
			m_sec = 59;

			m_minute--;
		}
		UpdateData(false);
	}
	Timer();

	//return 0;
}*/

//������ϰ
void CEx_Dlg::OnBnClickedButton2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	/*if (::MessageBox(m_hWnd, _T("��ϰʱ��δ��������ȷ��Ҫ����������"), _T("��Ϣ��ʾ"), MB_OKCANCEL) == IDCANCEL)
		return;*/
	//CString str;
	//str.Format(L"��߷�Ϊ %d", m_score);
	if (m_minute != 0 || m_sec != 0)
	{
		if (::MessageBox(m_hWnd, _T("��ϰʱ��δ��������ȷ��Ҫ����������"), _T("��Ϣ��ʾ"), MB_OKCANCEL) == IDCANCEL)


			
			return;
		
		//OnDestroy();
		//this->OnDestroy();
		CDialog::OnOK();//
		UpdateData(true);
		m_Sub = L"";
		m_Score[count2] = m_score;
		Highest = m_Score[count2];
		sign = count2;
		count2++;//����һ����ϰ������ϰ��������1
		
		for (int i = count2-1; i >= 0; i--)
		{
			if (m_Score[i]>Highest)
			{
				Highest = m_Score[i];
				sign = i;
			}
			
		}
		//m_sec = 0;//�����������ã������Ӱ�춨ʱ��������Ϊ0������miniuteΪ0���ᵯ����ϰʱ�������ʵ��δ��������ǿ�н�����ϰ
		m_score = 0;
		count = 0;//������ϰ�������������Ϊ0��ʼ
		//count1 = 0;//���¼�¼��һ����ϰ�ߵ���ϰ��Ŀ,�������������ã���Ӱ����ϰ��¼
		UpdateData(false);
		CString strc;
		strc.Format(L"%d", Highest);
		strc = L"��߷�Ϊ��" + strc+L"\r\n";
		strc = strc + L"��ϰ��Ϊ��" + t_name[sign];
		MessageBox(strc);

		//for (int i = 0; i < count; i++)
			//strop[i].Empty();
		//MessageBox(str);
	}

}

//��ʱ
void CEx_Dlg::OnTimer(UINT_PTR nIDEvent)//Ҫ������ʱ��ֹͣʱ���ð��½�����ϰ��ֵ�仯������

{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	UpdateData(true);

	
	if (m_minute > 0){//�ж��쳣��
		if (m_sec > 0)
			m_sec--;
		else
		{
			m_minute--;
			m_sec = 59;
		}
	}
	else{
		if (m_sec > 0)
			m_sec--;
		else
		{
			KillTimer(nIDEvent);
				MessageBox(L"��ϰʱ�������");//�Զ�����ʱ���ǿ�ƽ���ʱ���Ĳ���Ӧ����һ�µ�
				CDialog::OnOK();
				UpdateData(true);
				m_Sub = L"";
				m_Score[count2] = m_score;
				Highest = m_Score[count2];
				sign = count2;
				count2++;//����һ����ϰ������ϰ��������1

				for (int i = count2-1; i >= 0; i--)
				{
					if (m_Score[i]>Highest)
					{
						Highest = m_Score[i];
					sign = i;//����count��¼��߷���m_Score�����е�λ�ã�m_Score[]��t_name[]����������������һһ��Ӧ��
						
					}

				}
				//m_sec = 0;//�����������ã������Ӱ�춨ʱ��������Ϊ0������miniuteΪ0���ᵯ����ϰʱ�������ʵ��δ��������ǿ�н�����ϰ
				m_score = 0;
				count = 0;//������ϰ�������������Ϊ0��ʼ
				//count1 = 0;//���¼�¼��һ����ϰ�ߵ���ϰ��Ŀ,�������������ã���Ӱ����ϰ��¼
				UpdateData(false);
				CString strc;
				strc.Format(L"%d", Highest);
				strc = L"��߷�Ϊ��" + strc + L"\r\n";
				strc = strc + L"��ϰ��Ϊ��" + t_name[sign];
				MessageBox(strc);
				
				//OnCancel();
			
			
		}
	}
		/*if (m_sec>=0)
		 m_sec--;
		if (m_minute==0&&m_sec == 0)
		{
			MessageBox(L"��ϰʱ�������");
			OnCancel();
		}
		if (m_sec = 0){
			m_sec = 59;

			m_minute--;
		}*/
		UpdateData(false);
	 //do while

		//MessageBox(L"��ϰʱ�������");
		//OnCancel();

	
	CDialogEx::OnTimer(nIDEvent);
}


void CEx_Dlg::OnBnClickedButton3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	SetTimer(1, 1000, NULL);
	//GetDlgItem(IDC_EDIT5)->EnableWindow(TRUE);//�����ʼ��ʱ��༭���������������
}

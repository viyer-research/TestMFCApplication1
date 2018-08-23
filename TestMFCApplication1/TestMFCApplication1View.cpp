
// TestMFCApplication1View.cpp : implementation of the CTestMFCApplication1View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "TestMFCApplication1.h"
#endif

#include "TestMFCApplication1Doc.h"
#include "TestMFCApplication1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestMFCApplication1View

IMPLEMENT_DYNCREATE(CTestMFCApplication1View, CView)

BEGIN_MESSAGE_MAP(CTestMFCApplication1View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CTestMFCApplication1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CTestMFCApplication1View construction/destruction

CTestMFCApplication1View::CTestMFCApplication1View()
{
	// TODO: add construction code here

}

CTestMFCApplication1View::~CTestMFCApplication1View()
{
}

BOOL CTestMFCApplication1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CTestMFCApplication1View drawing

void CTestMFCApplication1View::OnDraw(CDC* /*pDC*/)
{
	CTestMFCApplication1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CTestMFCApplication1View printing


void CTestMFCApplication1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CTestMFCApplication1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTestMFCApplication1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTestMFCApplication1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CTestMFCApplication1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CTestMFCApplication1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CTestMFCApplication1View diagnostics

#ifdef _DEBUG
void CTestMFCApplication1View::AssertValid() const
{
	CView::AssertValid();
}

void CTestMFCApplication1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTestMFCApplication1Doc* CTestMFCApplication1View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestMFCApplication1Doc)));
	return (CTestMFCApplication1Doc*)m_pDocument;
}
#endif //_DEBUG


// CTestMFCApplication1View message handlers

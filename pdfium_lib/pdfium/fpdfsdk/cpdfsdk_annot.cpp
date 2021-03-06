// Copyright 2016 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#include "fpdfsdk/cpdfsdk_annot.h"

#include <algorithm>

#include "fpdfsdk/cpdfsdk_pageview.h"

#ifdef PDF_ENABLE_XFA
#include "fpdfsdk/fpdfxfa/cpdfxfa_context.h"
#endif  // PDF_ENABLE_XFA

CPDFSDK_Annot::CPDFSDK_Annot(CPDFSDK_PageView* pPageView)
    : m_pPageView(pPageView) {}

CPDFSDK_Annot::~CPDFSDK_Annot() {}

CPDFSDK_BAAnnot* CPDFSDK_Annot::AsBAAnnot() {
  return nullptr;
}

#ifdef PDF_ENABLE_XFA

bool CPDFSDK_Annot::IsXFAField() const {
  return false;
}

CXFA_FFWidget* CPDFSDK_Annot::GetXFAWidget() const {
  return nullptr;
}

CPDFXFA_Page* CPDFSDK_Annot::GetPDFXFAPage() {
  return m_pPageView ? m_pPageView->GetPDFXFAPage() : nullptr;
}

#endif  // PDF_ENABLE_XFA

int CPDFSDK_Annot::GetLayoutOrder() const {
  return 5;
}

CPDF_Annot* CPDFSDK_Annot::GetPDFAnnot() const {
  return nullptr;
}

CPDF_Annot::Subtype CPDFSDK_Annot::GetAnnotSubtype() const {
  return CPDF_Annot::Subtype::UNKNOWN;
}

bool CPDFSDK_Annot::IsSignatureWidget() const {
  return false;
}

void CPDFSDK_Annot::SetRect(const CFX_FloatRect& rect) {}

CFX_FloatRect CPDFSDK_Annot::GetRect() const {
  return CFX_FloatRect();
}

IPDF_Page* CPDFSDK_Annot::GetPage() {
#ifdef PDF_ENABLE_XFA
  CPDFXFA_Page* pXFAPage = GetPDFXFAPage();
  if (pXFAPage)
    return pXFAPage;
#endif  // PDF_ENABLE_XFA
  return GetPDFPage();
}

CPDF_Page* CPDFSDK_Annot::GetPDFPage() {
  return m_pPageView ? m_pPageView->GetPDFPage() : nullptr;
}

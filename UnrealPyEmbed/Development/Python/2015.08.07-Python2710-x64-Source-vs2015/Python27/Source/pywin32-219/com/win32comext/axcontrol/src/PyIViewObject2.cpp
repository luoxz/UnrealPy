// This file implements the IViewObject2 Interface and Gateway for Python.
// Generated by makegw.py

#include "axcontrol_pch.h"
#include "PyIViewObject.h"
#include "PyIViewObject2.h"

// @doc - This file contains autoduck documentation
// ---------------------------------------------------
//
// Interface Implementation

PyIViewObject2::PyIViewObject2(IUnknown *pdisp):
	PyIViewObject(pdisp)
{
	ob_type = &type;
}

PyIViewObject2::~PyIViewObject2()
{
}

/* static */ IViewObject2 *PyIViewObject2::GetI(PyObject *self)
{
	return (IViewObject2 *)PyIViewObject::GetI(self);
}

// @pymethod |PyIViewObject2|GetExtent|Description of GetExtent.
PyObject *PyIViewObject2::GetExtent(PyObject *self, PyObject *args)
{
	IViewObject2 *pIVO2 = GetI(self);
	if ( pIVO2 == NULL )
		return NULL;
	// @pyparm int|dwDrawAspect||Description for dwDrawAspect
	// @pyparm int|lindex||Description for lindex
	// @pyparm <o PyDVTARGETDEVICE>|targetDevice||Description for lindex

	DVTARGETDEVICE *ptd;
	PyObject *obptd;
	DWORD dwDrawAspect;
	LONG lindex;
	if ( !PyArg_ParseTuple(args, "iiO:GetExtent", &dwDrawAspect, &lindex, &obptd) )
		return NULL;
	BOOL bPythonIsHappy = TRUE;
	if (bPythonIsHappy && !PyObject_AsDVTARGETDEVICE( obptd, &ptd )) bPythonIsHappy = FALSE;
	if (!bPythonIsHappy) return NULL;
	SIZE sizel;
	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pIVO2->GetExtent( dwDrawAspect, lindex, ptd, &sizel );
	PY_INTERFACE_POSTCALL;

	if ( FAILED(hr) )
		return OleSetOleError(hr);
	return Py_BuildValue("ll", sizel.cx, sizel.cy);
}

// @object PyIViewObject2|Description of the interface
static struct PyMethodDef PyIViewObject2_methods[] =
{
	{ "GetExtent", PyIViewObject2::GetExtent, 1 }, // @pymeth GetExtent|Description of GetExtent
	{ NULL }
};

PyComTypeObject PyIViewObject2::type("PyIViewObject2",
		&PyIViewObject::type,
		sizeof(PyIViewObject2),
		PyIViewObject2_methods,
		GET_PYCOM_CTOR(PyIViewObject2));
// ---------------------------------------------------
//
// Gateway Implementation

STDMETHODIMP PyGViewObject2::Draw(
		DWORD dwDrawAspect,
		LONG lindex,
		void __RPC_FAR * pvAspect,
		DVTARGETDEVICE __RPC_FAR * ptd,
		HDC hdcTargetDev,
		HDC hdcDraw,
		LPCRECTL lprcBounds,
		LPCRECTL lprcWBounds,
		BOOL ( STDMETHODCALLTYPE __RPC_FAR *pfnContinue )( ULONG_PTR ),
		ULONG_PTR dwContinue)
		{ return PyGViewObject::Draw(dwDrawAspect, lindex, pvAspect, ptd, hdcTargetDev, hdcDraw, lprcBounds, lprcWBounds, pfnContinue, dwContinue); }

STDMETHODIMP PyGViewObject2::GetColorSet(
		DWORD dwDrawAspect,
		LONG lindex,
		void __RPC_FAR * pvAspect,
		DVTARGETDEVICE __RPC_FAR * ptd,
		HDC hicTargetDev,
		LOGPALETTE __RPC_FAR *__RPC_FAR * ppColorSet)
		{ return PyGViewObject::GetColorSet(dwDrawAspect, lindex, pvAspect, ptd, hicTargetDev, ppColorSet); }

STDMETHODIMP PyGViewObject2::Freeze(
		DWORD dwDrawAspect,
		LONG lindex,
		void __RPC_FAR * pvAspect,
		DWORD __RPC_FAR * pdwFreeze)
		{ return PyGViewObject::Freeze(dwDrawAspect, lindex, pvAspect, pdwFreeze); }

STDMETHODIMP PyGViewObject2::Unfreeze(
		DWORD dwFreeze)
		{ return PyGViewObject::Unfreeze(dwFreeze); }

STDMETHODIMP PyGViewObject2::SetAdvise(
		DWORD aspects,
		DWORD advf,
		IAdviseSink __RPC_FAR * pAdvSink)
		{ return PyGViewObject::SetAdvise(aspects, advf, pAdvSink); }

STDMETHODIMP PyGViewObject2::GetAdvise(
		DWORD __RPC_FAR * pAspects,
		DWORD __RPC_FAR * pAdvf,
		IAdviseSink __RPC_FAR *__RPC_FAR * ppAdvSink)
		{ return PyGViewObject::GetAdvise(pAspects, pAdvf,ppAdvSink ); }


STDMETHODIMP PyGViewObject2::GetExtent(
		/* [in] */ DWORD dwDrawAspect,
		/* [in] */ LONG lindex,
		/* [unique][in] */ DVTARGETDEVICE __RPC_FAR * ptd,
		/* [out] */ LPSIZEL lpsizel)
{
	PY_GATEWAY_METHOD;
	PyObject *obptd = PyObject_FromDVTARGETDEVICE(ptd);
	if (obptd==NULL) return PyCom_HandlePythonFailureToCOM();
	PyObject *result;
	HRESULT hr=InvokeViaPolicy("GetExtent", &result, "iiO", dwDrawAspect, lindex, obptd);
	Py_DECREF(obptd);
	if (FAILED(hr)) return hr;
	if (!PyArg_ParseTuple(result, "ll", &lpsizel->cx, &lpsizel->cx))
		hr = PyCom_HandlePythonFailureToCOM();
	return hr;
}


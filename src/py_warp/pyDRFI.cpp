#pragma once

#include "SalDRFI.h"
#include "conversion.h"
#include <boost/python.hpp>

using namespace boost::python;

class pyDRFI
{
public:
	pyDRFI(void) {
		_pSalDRFI = new SalDRFI();
	}

	void load(CStr dataFile = "Model.data") {
		_pSalDRFI->load(dataFile);
	}
	
	PyObject* getSalMap(PyObject *img) {
		NDArrayConverter cvt;
    	cv::Mat mat { cvt.toMat(img) };
    	cv::Mat result = _pSalDRFI->getSalMap(mat);
    	return cvt.toNDArray(result);
	}

	PyObject* getSalMapM(PyObject *img, double sigma, double k, double minSize) {
		NDArrayConverter cvt;
    	cv::Mat mat { cvt.toMat(img) };
    	cv::Mat result = _pSalDRFI->getSalMap(mat, sigma, k, minSize);
    	return cvt.toNDArray(result);
	}

private: // Helper variables
	SalDRFI* _pSalDRFI;
};

static void init()
{
    Py_Initialize();
    import_array();
}

BOOST_PYTHON_MODULE(pyDRFI)
{
    class_<pyDRFI>("pyDRFI")
    	.def("load", &pyDRFI::load)
    	.def("getSalMap", &pyDRFI::getSalMap)
    	.def("getSalMapM", &pyDRFI::getSalMapM)
    ;
}

//Y_hat = mexRF_predict(X',model.lDau,model.rDau,model.nodestatus,model.nrnodes,model.upper,model.avnode,model.mbest,model.ndtree,model.ntree);
drfi_python
========
This code is forked from https://github.com/playerkk/drfi_cpp
And I add python interface to DRFI
1. Compile
cd root_dir
make all

Then, you will find executable file DRFI and python module pyDRFI.so under the root directory

2. Run
```python
import pyDRFI
import cv2

DRFI = pyDRFI.pyDRFI()
DRFI.load('drfiModelCpp.data')
im = cv2.imread('0_0_272.png')
sal = DRFI.getSalMap(im)
```

C++ implementation of the paper Salient Object Detection: A Discriminative Regional Feature Integration Approach

This implementation is dependent on the OpenCV library. For Windows users, a Visual Studio 2010 solution is created. For Linux users, a naive Makefile is provided. Make sure that the OpenMP switch is turned on to achieve the best performance.

Before testing, you might want to download our pre-trained Random Forest model, which is available at http://jianghz.me/drfi/files/drfiModelCpp.zip. Put it under the same folder with generated binary DRFI file.

For more details, check out our technical report http://arxiv.org/pdf/1410.5926v1.

Tested on Windows 7 64bit with Visual Studio 2010 and Ubuntu 12.04 64bit with GCC 4.8.3.

Bugs, comments are welcome to hzjiang@cs.umass.edu.

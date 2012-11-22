************
Installation
************

Prerequisites
=============

Make sure these projects are configured and built (http://pcraster.sourceforge.net and http://sourceforge.net/projects/pcraster):

* DevEnv-1.3: http://pcraster.sourceforge.net

Checkout/configure/build::

  $ svn checkout https://pcraster.svn.sourceforge.net/svnroot/pcraster/RasterFormat/trunk RasterFormat
  $ export RASTERFORMAT=`pwd`/RasterFormat
  $ source $RASTERFORMAT/environment/configuration/bash_profile
  $ configurecmakeproject.py release RasterFormat # Or debug.
  $ make -C $RASTERFORMAT


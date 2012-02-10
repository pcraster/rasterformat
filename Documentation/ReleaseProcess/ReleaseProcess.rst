***************
Release process
***************

.. |date| date::

:Author: PCRaster R&D team
:Contact: k.dejong@geo.uu.nl
:Generated on: |date|



Prerequisites
=============
RasterFormat depends on one other PCRaster project::

  DevEnv

Feature release
===============
Given release branch ``x.y`` and release tag ``x.y.z``, the steps are:

* Create release branch:

  ::

    svn copy -m"Creating release branch x.y of trunk" \
      https://pcraster.svn.sourceforge.net/svnroot/pcraster/RasterFormat/trunk \
      https://pcraster.svn.sourceforge.net/svnroot/pcraster/RasterFormat/branches/x.y

* Create release tag:

  ::

    svn copy -m"Creating release tag x.y.z of branches/x.y" \
      https://pcraster.svn.sourceforge.net/svnroot/pcraster/RasterFormat/branches/x.y \
      https://pcraster.svn.sourceforge.net/svnroot/pcraster/RasterFormat/tags/x.y.z

Bug-fix release
===============

TODO

.. target-notes::

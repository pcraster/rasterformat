#!/usr/bin/env bash
# set -e


# Where to store temp patch files
patch_root="/tmp"

# Root of latest GDAL sources
gdal_root="$HOME/tmp/gdal-2.2.0"


for gdal_filename in `ls $gdal_root/frmts/pcraster/libcsf/*`; do

    filename=$(basename $gdal_filename)
    patch_filename="$patch_root/$filename.patch"

    diff -u $filename $gdal_filename 2>&1 > $patch_filename

    if [ $? != 0 ]; then
        echo -e "\n\n"
        cat $patch_filename
        echo "Patch our copy of $filename? [y/n/q](y)"
        read answer
        answer=${answer:-y}

        if [ "$answer" == "y" ]; then
            patch < $patch_filename
        elif [ "$answer" == "n" ]; then
            echo "--→ Skip $filename"
        elif [ "$answer" == "q" ]; then
            exit 0
        else
            exit 1
        fi

        rm $patch_filename
    fi

done

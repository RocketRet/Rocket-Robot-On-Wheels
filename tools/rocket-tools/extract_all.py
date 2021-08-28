#!/usr/bin/env python3
import os

if __name__ == "__main__":
    for i in range(1944):
        call_string = "./extract_texture ../../baserom.us.z64 %d /mnt/c/n64/rrow_textures/rrow_asset_%d.png" % (i, i)
        os.system(call_string)
/*------------------------------------------------------------------------------
Copyright (c) 2008 The Khronos Group Inc.

All Rights Reserved.  This code is protected by copyright laws and contains
material proprietary to the Khronos Group, Inc.  This is UNPUBLISHED
PROPRIETARY SOURCE CODE that may not be disclosed in whole or in part to third
parties, and may not be reproduced, republished, distributed, transmitted,
displayed, broadcast or otherwise exploited in any manner without the express
prior written permission of Khronos Group.

The receipt or possession of this code does not convey any rights to reproduce,
disclose, or distribute its contents, or to manufacture, use, or sell anything
that it may describe, in whole or in part other than under the terms of the
Khronos Adopters Agreement or Khronos Conformance Test Source License Agreement
as executed between Khronos and the recipient.

For the avoidance of doubt, this code when provided: a) under the Khronos
Conformance Test Source License Agreement is for the sole purpose of creating
conformance tests for delivery to Khronos and does not provide for formally
testing products or use of Khronos trademarks on conformant products; b) under
the Khronos Adopters Agreement is for the sole purpose of formally
administering tests to products pursuant to the Khronos Conformance Process
Document.

Khronos, OpenKODE, OpenVG, OpenWF, glFX, OpenMAX and OpenSL ES are trademarks
of the Khronos Group Inc.  COLLADA is a trademark of Sony Computer
Entertainment Inc. used by permission by Khronos.  OpenGL and OpenML are
registered trademarks and the OpenGL ES logo is a trademark of Silicon Graphics
Inc. used by permission by Khronos. 

Use, duplication or disclosure by the Government is subject to restrictions as
set forth in subdivision (c)(1)(ii) of the Rights in Technical Data and
Computer Software clause at DFARS 252.227-7013, and/or in similar or successor
clauses in the FAR, DOD or NASA FAR Supplement. Unpublished rights reserved
under the Copyright Laws of the United States and other countries.
------------------------------------------------------------------------------*/

#include "../main.h"
#include "../util/util.h"

CT_Result C20101_MatrixMode_by_HUONE(CT_File *AnsFile)
{
    VGfloat   m1[9] = {1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f};
    VGfloat   m2[9] = {2.0f, 0.0f, 0.0f, 0.0f, 2.0f, 0.0f, 0.0f, 0.0f, 1.0f};
    VGfloat   result[9];
    VGfloat   answer[45];
    
    VGfloat   tx  = 1.0f, ty = 1.0f;
    VGfloat   rot = 90.0f;
    VGfloat   sx  = 0.5f, sy = 0.5f;
    VGfloat   shx = 1.0f, shy = -1.0f;
    VGint     i,j;

    for (i = VG_MATRIX_PATH_USER_TO_SURFACE, j=0; i <= VG_MATRIX_GLYPH_USER_TO_SURFACE; i++, j+=9) {
        vgSeti(VG_MATRIX_MODE, i);
        vgLoadIdentity();
        vgLoadMatrix(m1);
        vgMultMatrix(m2);
        vgTranslate(tx, ty);
        vgRotate(rot);
        vgScale(sx, sy);
        vgShear(shx, shy);

        vgGetMatrix(result);

        MEMCPY (&answer[j], &result[0], sizeof(VGfloat)*9);
    }

    if ( vgGetError() == VG_NO_ERROR )
        return SaveValueFile(45, answer, AnsFile);
    else
        return CT_ERROR;
}


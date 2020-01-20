#include <systypes.h>
#include <mtktypes.h>
#include <utils.h>
#include <sha1.h>
#include <vibro.h>
#include <drivers/lcd.h>

#define _USEBATTERY_ (1)

extern uint32_t ROM_Image_Base, ROM_Image_Limit;

void *BL_CheckFileByDescriptor(BL_Descr File)
{
    void *ExtBLEntryPoint = NULL;

    File.m_bl_begin_dev_addr += ROM_Image_Base;
    File.m_bl_boundary_dev_addr += ROM_Image_Base;

    if ((File.m_bl_begin_dev_addr > ROM_Image_Base) &&
        (File.m_bl_boundary_dev_addr < ROM_Image_Limit))
    {
        pFILE_INFO_v1 FileInfo = (pFILE_INFO_v1)File.m_bl_begin_dev_addr;
        if ((GFH_GETMAGIC(FileInfo->hdr.magic) == GFH_HDR_MAGIC) &&
            (FileInfo->hdr.type == GFH_FILE_INFO) &&
            (FileInfo->hdr.size == sizeof(FILE_INFO_v1)) &&
            (FileInfo->file_type == ARM_EXT_BL) &&
            (FileInfo->flash_dev == F_SF) &&
            (FileInfo->load_addr >= ROM_Image_Base) &&
            (FileInfo->load_addr + FileInfo->file_len < ROM_Image_Limit))
        {
            uint32_t SizeToCheck = FileInfo->file_len - FileInfo->sig_len;
            pSHA1 CheckedHash;
            if (FileInfo->sig_type == SIG_NONE)
                ExtBLEntryPoint = (void *)(FileInfo->load_addr + FileInfo->jump_offset);
            else if ((FileInfo->sig_type == SIG_PHASH) &&
                     (FileInfo->sig_len == sizeof(MTK_PHASH)) &&
                     (*(uint32_t *)(FileInfo->load_addr + SizeToCheck - 4) == MTK_FEND))
            {
                CheckedHash = SHA1_ProcessData((uint8_t *)FileInfo->load_addr, SizeToCheck);
                if (CheckedHash != NULL)
                {
                    pMTK_PHASH FileHash = (pMTK_PHASH)(FileInfo->load_addr + SizeToCheck);

                    if ((swab32(CheckedHash->H0) == FileHash->H0) &&
                        (swab32(CheckedHash->H1) == FileHash->H1) &&
                        (swab32(CheckedHash->H2) == FileHash->H2) &&
                        (swab32(CheckedHash->H3) == FileHash->H3) &&
                        (swab32(CheckedHash->H4) == FileHash->H4))
                    {
                        ExtBLEntryPoint = (void *)(FileInfo->load_addr + FileInfo->jump_offset);
                    }
                    else
                    {
                    }
                }
            }
        }
    }
    return ExtBLEntryPoint;
}

int main(void)
{
    pSF_HEADER_v1 sf_header = (pSF_HEADER_v1)ROM_Image_Base;
    // HW_VibroToggle(true);

    HW_LCD_SetISINKMode(false);
    HW_LCD_SetISINKParameters(ISINK_CH0, IC_8mA, true);

    return 0;
}
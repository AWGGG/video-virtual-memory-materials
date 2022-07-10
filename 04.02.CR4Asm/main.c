#include <ntifs.h>
#include <intrin.h>

#include "win10.h"
#include "x64.h"

VOID
DriverUnload(PDRIVER_OBJECT DriverObject)
{
    DbgPrint("�ټ�! %wZ\n", &DriverObject->DriverName);
}

NTSTATUS
DriverEntry(PDRIVER_OBJECT  DriverObject, PUNICODE_STRING RegistryPath)
{
    UNREFERENCED_PARAMETER(RegistryPath);

    DbgPrint("���! %wZ\n", &DriverObject->DriverName);
    DriverObject->DriverUnload = DriverUnload;

    //  __readcr4() & (1 << 12)
    //  __readcr4() & 0b1000000000000
    if (__readcr4() & 0x1000)
        DbgPrint("5����ҳ\n");
    else
        DbgPrint("4����ҳ\n");

    CR4 Cr4 = { .Value = __readcr4() };
    if (Cr4.Fields.LA57)
        DbgPrint("5����ҳ\n");
    else
        DbgPrint("4����ҳ\n");

    return STATUS_SUCCESS;
}

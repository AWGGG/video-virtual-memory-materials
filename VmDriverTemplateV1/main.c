#include <ntifs.h>

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



    return STATUS_SUCCESS;
}

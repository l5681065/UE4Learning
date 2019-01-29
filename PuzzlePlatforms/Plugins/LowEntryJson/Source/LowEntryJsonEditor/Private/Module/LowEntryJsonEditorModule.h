// Copyright Low Entry. All Rights Reserved.

#pragma once


#include "ILowEntryJsonEditorModule.h"


class FLowEntryJsonEditorModule : public ILowEntryJsonEditorModule
{
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

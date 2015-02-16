// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Editor/UnrealEd/Public/Toolkits/BaseToolkit.h"
#include "SCompoundWidget.h"


/**
 * Mode Toolkit for the Interior Editor Mode
 */
class FInteriorToolKit : public FModeToolkit
{
public:
	virtual void RegisterTabSpawners(const TSharedRef<class FTabManager>& TabManager) override;
	virtual void UnregisterTabSpawners(const TSharedRef<class FTabManager>& TabManager) override;

	/** Initializes the geometry mode toolkit */
	virtual void Init(const TSharedPtr< class IToolkitHost >& InitToolkitHost);

	/** IToolkit interface */
	virtual FName GetToolkitFName() const override;
	virtual FText GetBaseToolkitName() const override;
	virtual class FInteriorEditorMode* GetEditorMode() const override;
	virtual TSharedPtr<class SWidget> GetInlineContent() const override;

	void NotifyToolChanged();
	void NotifyBrushChanged();

private:
	/** Geometry tools widget */
	TSharedPtr<class SInteriorEditor> Widget;
};

/**
 * Slate widgets for the Interior Editor Mode
 */
class SInteriorEditor: public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SInteriorEditor){}
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs, TSharedRef<FInteriorToolKit> InParentToolkit);

	void NotifyToolChanged();
	void NotifyBrushChanged();

protected:
	class FInteriorEditorMode* GetEditorMode() const;

	FText GetErrorText() const;
//	bool GetLandscapeEditorIsEnabled() const;
	bool GetIsPropertyVisible(const struct FPropertyAndParent& PropertyAndParent) const;

	void OnTestCommand(FName ModeName);
//	void OnChangeMode(FName ModeName);
//	bool IsModeEnabled(FName ModeName) const;
//	bool IsModeActive(FName ModeName) const;

protected:
	// Command list bound to this window
	TSharedPtr<FUICommandList> CommandList;
	TSharedPtr<SErrorText> Error;

	TSharedPtr<class IDetailsView> DetailsPanel;
};

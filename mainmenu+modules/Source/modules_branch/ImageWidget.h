// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ImageWidget.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class MODULES_BRANCH_API
UImageWidget : public 
UUserWidget
{
	GENERATED_BODY()

public:
	UImageWidget(const FObjectInitializer& ObjectInitializer);

protected:
	virtual void
		NativeConstruct() override;

	void LoadImages();
	void UpdateDisplayedImage();

public:

	UFUNCTION(BlueprintCallable, Category = "Image Navigation")
	void ShowNextImage();

	UFUNCTION(BlueprintCallable, Category = "Image Navigation")
	void ShowPreviousImage();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Images")
	TArray<UTexture2D*> Images;

	UPROPERTY()
	int32 CurrentImageIndex;

	UPROPERTY(meta = (BindWidget))
		class UImage* ImageDisplay;
	
};

// Fill out your copyright notice in the Description page of Project Settings.


#include "ImageWidget.h"
#include "Components/Image.h"
#include "Engine/Texture2D.h"

UImageWidget::UImageWidget(
	const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, CurrentImageIndex(0)

{
}

void
UImageWidget::NativeConstruct() {
	Super::NativeConstruct();

	LoadImages();

	UpdateDisplayedImage();
}

void
UImageWidget::LoadImages() {
	FString ImagePath = "/Game/Images/";

	for (int32 i = 1; i <= 27; i++)
	{
		FString FullPath = ImagePath + "Image" + FString::FromInt(i);
		UTexture2D* LoadedImage = Cast<UTexture2D>(StaticLoadObject(UTexture2D::StaticClass(), nullptr, *FullPath));
		if (LoadedImage) {
			Images.Add(LoadedImage);
		}
	}
}

void 
UImageWidget::UpdateDisplayedImage()
{
	if (Images.Num() > 0) {
		CurrentImageIndex = FMath::Clamp(CurrentImageIndex, 0, Images.Num() - 1);
		if (ImageDisplay && Images.IsValidIndex(CurrentImageIndex)) {
			ImageDisplay->SetBrushFromTexture(Images[CurrentImageIndex]);
		}
	}
}

void
UImageWidget::ShowNextImage() {
	CurrentImageIndex++;
	if (CurrentImageIndex >= Images.Num())
	{
		CurrentImageIndex = 0;
	}
	UpdateDisplayedImage();
}

void
UImageWidget::ShowPreviousImage()
{
	CurrentImageIndex--;
	if (CurrentImageIndex < 0) {
		CurrentImageIndex = Images.Num() - 1;
	}
	UpdateDisplayedImage();
}
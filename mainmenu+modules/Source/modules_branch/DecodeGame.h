#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <unordered_map>
#include "DecodingGame.generated.h"

UCLASS()
class FILE_FRENZY_API ADecodingGame : public AActor
{
    GENERATED_BODY()

public:
    // Constructor
    ADecodingGame();

    // Encoded and original messages
    FString EncodedMessage;
    FString OriginalMessage;
    std::unordered_map<char, char> DecodeKey;

    // Functions
    void InitializeGame(); // Initializes the game
    FString EncodeMessage(const FString& Message); // Encodes a message
    FString DecodeMessage(const FString& Encoded); // Decodes a message

    UFUNCTION(BlueprintCallable, Category = "Decoding")
    FString GetEncodedMessage() const;

    UFUNCTION(BlueprintCallable, Category = "Decoding")
    void SubmitAnswer(const FString& PlayerInput);

    UFUNCTION(BlueprintCallable, Category = "Decoding")
    FString GetDecodeKey() const;

    UFUNCTION(BlueprintCallable, Category = "Decoding")
    int32 GetRemainingTime() const;


private:
    TArray<FString> Messages; // Predefined messages
};

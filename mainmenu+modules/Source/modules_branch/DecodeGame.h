#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <unordered_map>
#include "DecodingGame.generated.h"

UCLASS()
class MYGAME_API ADecodingGame : public AActor
{
    GENERATED_BODY()

public:
    // Constructor
    ADecodingGame();

    // Encoded message and decoding key
    FString EncodedMessage;
    FString OriginalMessage;
    std::unordered_map<char, char> DecodeKey;

    // Functions
    void InitializeGame();
    FString EncodeMessage(const FString& Message);
    FString DecodeMessage(const FString& Encoded);

private:
    TArray<FString> Messages;
};

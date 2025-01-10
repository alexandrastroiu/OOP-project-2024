#include "DecodingGame.h"

// Constructor
ADecodingGame::ADecodingGame()
{
    PrimaryActorTick.bCanEverTick = true;

    // Example messages
    Messages = {
        TEXT("HELLO WORLD"),
        TEXT("UNREAL ENGINE"),
        TEXT("C++ IS AWESOME"),
        TEXT("DECODING GAME"),
        TEXT("HAVE FUN"),
        TEXT("GOOD LUCK")
    };
}

// Initializes the game
void ADecodingGame::InitializeGame()
{
    // Select a random message
    OriginalMessage = Messages[FMath::RandRange(0, Messages.Num() - 1)];

    // Generate a simple substitution cipher
    DecodeKey.clear();
    for (char Letter = 'A'; Letter <= 'Z'; ++Letter)
    {
        char Encoded = 'A' + FMath::RandRange(0, 25);
        DecodeKey.Add(Letter, Encoded);
    }

    // Encode the message
    EncodedMessage = EncodeMessage(OriginalMessage);
}

// Encodes a message using the DecodeKey
FString ADecodingGame::EncodeMessage(const FString& Message)
{
    FString Result = "";
    for (TCHAR Letter : Message)
    {
        if (DecodeKey.Contains(Letter))
        {
            Result += DecodeKey[Letter];
        }
        else
        {
            Result += Letter; // Keep non-alphabet characters
        }
    }
    return Result;
}

// Decodes a message using the DecodeKey
FString ADecodingGame::DecodeMessage(const FString& Encoded)
{
    FString Result = "";
    for (TCHAR Letter : Encoded)
    {
        // Find the original letter
        for (const auto& Pair : DecodeKey)
        {
            if (Pair.Value == Letter)
            {
                Result += Pair.Key;
                break;
            }
        }
    }
    return Result;
}

FString ADecodeGame::GetEncodedMessage() const {
    return EncodedMessage; // Return the encoded message
}

void ADecodeGame::SubmitAnswer(const FString& PlayerInput) {
    if (PlayerInput.Equals(OriginalMessage, ESearchCase::IgnoreCase)) {
        // Correct answer logic
        UE_LOG(LogTemp, Warning, TEXT("Correct Answer!"));
    }
    else {
        // Incorrect answer logic
        UE_LOG(LogTemp, Warning, TEXT("Wrong Answer!"));
    }
}

FString ADecodeGame::GetDecodeKey() const {
    FString Key;
    for (const auto& Pair : DecodeKey) {
        Key += FString::Printf(TEXT("%c -> %c\n"), Pair.Key, Pair.Value);
    }
    return Key;
}

int32 ADecodeGame::GetRemainingTime() const {
    return FMath::Clamp(RemainingTime, 0, MaxTime); // Return the remaining time
}

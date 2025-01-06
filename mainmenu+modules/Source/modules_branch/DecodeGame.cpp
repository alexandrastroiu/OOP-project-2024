#include "DecodingGame.h"
#include "Math/UnrealMathUtility.h"

// Constructor
ADecodingGame::ADecodingGame()
{
    // Define messages
    Messages = { TEXT(""), TEXT("UNREAL ENGINE"), TEXT("DECODING GAME"), TEXT("SECRET CODE"), TEXT("FUN WITH GAMES") };

    // Define decoding key (example key)
    DecodeKey = {
        {'A', 'C'}, {'B', 'F'}, {'C', 'E'}, {'D', 'H'},
        {'E', 'K'}, {'F', 'L'}, {'G', 'M'}, {'H', 'P'},
        {'I', 'Q'}, {'J', 'R'}, {'K', 'S'}, {'L', 'T'},
        {'M', 'U'}, {'N', 'V'}, {'O', 'W'}, {'P', 'X'},
        {'Q', 'Y'}, {'R', 'Z'}, {'S', 'A'}, {'T', 'B'}
    };

    // Initialize game logic
    InitializeGame();
}

// Initialize the game by selecting a random message and encoding it
void ADecodingGame::InitializeGame()
{
    // Select a random message
    int32 RandomIndex = FMath::RandRange(0, Messages.Num() - 1);
    OriginalMessage = Messages[RandomIndex];

    // Encode the message
    EncodedMessage = EncodeMessage(OriginalMessage);
}

// Encode a message using the DecodeKey
FString ADecodingGame::EncodeMessage(const FString& Message)
{
    FString Encoded;
    for (TCHAR Char : Message)
    {
        if (DecodeKey.find(Char) != DecodeKey.end())
        {
            Encoded += DecodeKey[Char];
        }
        else
        {
            Encoded += Char; // Leave spaces or unsupported characters as is
        }
    }
    return Encoded;
}

// Decode a message using the reverse of DecodeKey
FString ADecodingGame::DecodeMessage(const FString& Encoded)
{
    FString Decoded;
    std::unordered_map<char, char> ReverseKey;

    // Create a reverse key
    for (auto& Pair : DecodeKey)
    {
        ReverseKey[Pair.second] = Pair.first;
    }

    for (TCHAR Char : Encoded)
    {
        if (ReverseKey.find(Char) != ReverseKey.end())
        {
            Decoded += ReverseKey[Char];
        }
        else
        {
            Decoded += Char;
        }
    }
    return Decoded;
}

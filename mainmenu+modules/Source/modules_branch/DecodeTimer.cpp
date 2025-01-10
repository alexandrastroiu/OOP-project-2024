void ADecodingGame::StartTimer()
{
    GetWorld()->GetTimerManager().SetTimer(
        TimerHandle, this, &ADecodingGame::OnTimerEnd, RemainingTime, false
    );
}

void ADecodingGame::OnTimerEnd()
{
    // Handle timeout
    UE_LOG(LogTemp, Warning, TEXT("Time's up! You failed to decode the message!"));
}

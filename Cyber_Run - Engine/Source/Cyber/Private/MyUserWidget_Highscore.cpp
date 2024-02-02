// MyUserWidget:Highscore.cpp

#include <string>
#include "MyUserWidget_Highscore.h"
#include "Components/TextBlock.h"
#include "Blueprint/UserWidget.h"


void UMyUserWidget_Highscore::NativeConstruct()
{
	Super::NativeConstruct();

	//Start Timer
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &UMyUserWidget_Highscore::TimerCountdown, 1.0f, true);
}


void UMyUserWidget_Highscore::TimerCountdown() {

	//Timer von 120 runter zählen
	timer--;

	//Wenn der Timer >=0 ist wird runter gezählt. Ist der Timer <= 0, dann GameOver
	if (timer >= 0) {
		Time_Text->SetText(FText::FromString(FString::FromInt(timer)));


		//Score erhöhen, wenn ...
		score += 10;

		//Score und Highscore vergleichen
		if (score >= 0) {
			Highscore_Text->SetText(FText::FromString(FString::FromInt(score)));
		}
	}

	if (timer <= 0) {
		GamePaused = true;
		PauseGame();

		/*if (GameOverWidgetClass) {
			UUserWidget* GameOverWidget = CreateWidget<UUserWidget>(GetWorld(), GameOverWidgetClass);
			//VerticalBox->AddChildToVerticalBox(widget);
			if (GameOverWidget) {
				GameOverWidget->AddToViewport();
				GetWorld()->GetFirstPlayerController()->SetPause(true);
				UE_LOG(LogTemp, Warning, TEXT("GameOverWidget erstellt"));
				UpdateHighScore();
			}
		}*/
		
	}
}


void UMyUserWidget_Highscore::UpdateHighScore() {

	//Wenn der im Spiel erziele score größer ist als der derzeitige Highscore, dann wird der
	// derzeitige score zum Highscore
	if (score >= HighScore) {
		HighScore = score;
		SaveHighScore();
	}
}

void UMyUserWidget_Highscore::SaveHighScore() {

	//Code.....

}

//Pausiert das Spiel
void UMyUserWidget_Highscore::PauseGame() {
	if (GamePaused == true) {
		GetWorld()->GetTimerManager().PauseTimer(TimerHandle);
		GetWorld()->GetFirstPlayerController()->SetPause(true);
	}
}

//Startet das Spiel wieder
void UMyUserWidget_Highscore::ResumeGame() {
	if (GamePaused == false) {
		GetWorld()->GetTimerManager().UnPauseTimer(TimerHandle);
		GetWorld()->GetFirstPlayerController()->SetPause(false);
	}
}

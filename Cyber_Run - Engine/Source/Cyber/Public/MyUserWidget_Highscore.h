// MyUserWidget:Highscore.h

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyUserWidget_Highscore.generated.h"

/**
 * 
 */
UCLASS()
class CYBER_API UMyUserWidget_Highscore : public UUserWidget
{
	GENERATED_BODY()

	protected:
		virtual void NativeConstruct() override;
	
	public:
		// Variablen für Punkte und Zeit
		int score = 0;
		unsigned int timer = 20;
		bool GamePaused = false;


		// Function
		void TimerCountdown();
		void UpdateHighScore();
		void SaveHighScore();

		void PauseGame();
		void ResumeGame();


		//Den Textblock names Highscore_Text aufrufen bzw. benutzen
		UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
			class UTextBlock* Highscore_Text;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InGame-BP")
			int HighScore;


		//Den Textblock names Time_Text aufrufen bzw. benutzen
		UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
			class UTextBlock* Time_Text;


		FTimerHandle TimerHandle;
};

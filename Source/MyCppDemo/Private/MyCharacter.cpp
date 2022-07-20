// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("My Spring Arm Component"));
	// 设置父子层级关系
	SpringArmComponent->SetupAttachment(RootComponent);
	
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("My Camera Component"));
	CameraComponent->SetupAttachment(SpringArmComponent);
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMyCharacter::MovingForwardFunc(float axisValue)
{
	UE_LOG(LogTemp, Log, TEXT("Forward = %f"), axisValue)

		AddMovementInput(GetActorForwardVector(), axisValue);
}

void AMyCharacter::MovingRightFunc(float axisValue)
{
	UE_LOG(LogTemp, Log, TEXT("Right = %f"), axisValue)
		AddMovementInput(GetActorRightVector(), axisValue);
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//void AMyCharacter::TMethodPtr< AMyCharacter >



// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//GetActorForwardVector
	//AddMovementInput
	////
	// PlayerInputComponent->BindAction();
	
	PlayerInputComponent->BindAxis<AMyCharacter>(FName("MovingForward"), this, &AMyCharacter::MovingForwardFunc);
	PlayerInputComponent->BindAxis<AMyCharacter>(FName("MovingRight"), this, &AMyCharacter::MovingRightFunc);
}


// Fill out your copyright notice in the Description page of Project Settings.


#include "ACharacter.h"

// Sets default values
AACharacter::AACharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPRINGARM"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));

	SpringArm->SetupAttachment(RootComponent);
	Camera->SetupAttachment(SpringArm);

	GetMesh()->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -90.0f), FRotator(0.0f, -88.0f, 0.0f));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_HUMAN(TEXT("/Game/InfinityBladeWarriors/Character/CompleteCharacters/sk_CharM_Base.sk_CharM_Base"));
	if (SK_HUMAN.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SK_HUMAN.Object);
	}
	GetMesh()->SetAnimationMode(EAnimationMode::AnimationBlueprint);
	static ConstructorHelpers::FClassFinder<UAnimInstance> ANIM_WALK(TEXT("/Game/animation/Warrior_Anim_Blueprint.Warrior_Anim_Blueprint_C"));
	if (ANIM_WALK.Succeeded())
	{
		GetMesh()->SetAnimInstanceClass(ANIM_WALK.Class);
	}

	SpringArm->TargetArmLength = 450.0f;
	SpringArm->bUsePawnControlRotation = true;
	SpringArm->bDoCollisionTest = true;

	
	bUseControllerRotationYaw = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;

}

// Called when the game starts or when spawned
void AACharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AACharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AACharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AACharacter::UpDown);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AACharacter::LeftRight);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &AACharacter::Turn);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AACharacter::LookUp);
}

void AACharacter::UpDown(float NewAxisValue)
{
	AddMovementInput(FRotationMatrix(FRotator(0.0f, GetControlRotation().Yaw, 0.0f)).GetUnitAxis(EAxis::X), NewAxisValue);
}

void AACharacter::LeftRight(float NewAxisValue)
{
	AddMovementInput(FRotationMatrix(FRotator(0.0f, GetControlRotation().Yaw, 0.0f)).GetUnitAxis(EAxis::Y), NewAxisValue);
}

void AACharacter::Turn(float NewAxisValue)
{
	AddControllerYawInput(NewAxisValue);
}

void AACharacter::LookUp(float NewAxisValue)
{
	AddControllerPitchInput(NewAxisValue);
}

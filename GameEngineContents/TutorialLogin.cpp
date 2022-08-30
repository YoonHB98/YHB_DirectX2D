#include "PreCompile.h"
#include "TutorialLogin.h"
#include <conio.h>

TutorialLogin::TutorialLogin() 
{
}

TutorialLogin::~TutorialLogin() 
{
}

void TutorialLogin::Start()
{
	SetTexture("loginwindow.png");
	SetLocalPosition(float4(-50,50));
	SetLocalScale(float4(420, 280));

	Collision = CreateComponent<GameEngineCollision>();
	Collision->GetTransform().SetLocalPosition(float4(-50, 27));
	Collision->GetTransform().SetLocalScale(float4(180, 25));
	Collision->ChangeOrder(OBJECTORDER::UI);

	Collision2 = CreateComponent<GameEngineCollision>();
	Collision2->GetTransform().SetLocalPosition(float4(-50, -10));
	Collision2->GetTransform().SetLocalScale(float4(125, 22));
	Collision2->ChangeOrder(OBJECTORDER::UI);

	Font = CreateComponent<Myfont>();
}

void TutorialLogin::Update(float _DeltaTime)
{
	ChangeZPos(-50);
	if (true == GameEngineInput::GetInst()->IsDown("MouseClick")
		&& MouseCheck(Collision))
	{
		ChangeTexture("loginwindow2.png");
		PassWord = true;
	}
	if (true == GameEngineInput::GetInst()->IsDown("MouseClick")
		&& MouseCheck(Collision2)
		&&(Text == "angelkawaii2"|| Text == " angelkawaii2"))
	{
		GlobalContentsValue::TutorialLogin = false;
		GlobalContentsValue::WebCamWindow = true;
		GlobalContentsValue::Tutorial = false;
		GlobalContentsValue::RemainLinenum = 7;
		Off();
	}
	if (PassWord)
	{
		for (int i = 47; i < 98; i++)
		{

			if (GetAsyncKeyState(i) & 0x0001)
			{
				if (i <= 57)
				{
					char A = i;
					Text = Text + A;
					Font->TextDraw(Text, "Galmuri9", float4(350, 230), float4(0.271f, 0.3294f, 0.56862f, 1), 15.0f);
					break;
				}
				else
				{
					char A = i;
					A = A + 32;
					Text = Text + A;
					Font->TextDraw(Text, "Galmuri9", float4(350, 230), float4(0.271f, 0.3294f, 0.56862f, 1), 15.0f);
					break;
				}

			}


		}
		if (true == GameEngineInput::GetInst()->IsDown("A"))
		{
			Text = Text + 'a';
			Font->TextDraw(Text, "Galmuri9", float4(350, 230), float4(0.271f, 0.3294f, 0.56862f, 1), 15.0f);
		}
		if (true == GameEngineInput::GetInst()->IsDown("E"))
		{
			Text = Text + 'e';
			Font->TextDraw(Text, "Galmuri9", float4(350, 230), float4(0.271f, 0.3294f, 0.56862f, 1), 15.0f);
		}
		if (true == GameEngineInput::GetInst()->IsDown("S"))
		{
			Text = Text + 's';
			Font->TextDraw(Text, "Galmuri9", float4(350, 230), float4(0.271f, 0.3294f, 0.56862f, 1), 15.0f);
		}
		if (true == GameEngineInput::GetInst()->IsDown("Q"))
		{
			Text = Text + 'q';
			Font->TextDraw(Text, "Galmuri9", float4(350, 230), float4(0.271f, 0.3294f, 0.56862f, 1), 15.0f);
		}
		if (true == GameEngineInput::GetInst()->IsDown("W"))
		{
			Text = Text + 'w';
			Font->TextDraw(Text, "Galmuri9", float4(350, 230), float4(0.271f, 0.3294f, 0.56862f, 1), 15.0f);
		}
		if (true == GameEngineInput::GetInst()->IsDown("BACKSPACE"))
		{
			if (!Text.empty()) {
				Text.pop_back();
				Font->TextDraw(Text, "Galmuri9", float4(350, 230), float4(0.271f, 0.3294f, 0.56862f, 1), 15.0f);
			}
		}


	}
	


}

void TutorialLogin::End()
{
}
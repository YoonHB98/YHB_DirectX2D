#pragma once
#include <GameEngineCore/CoreMinimal.h>

// Ό³Έν :


class GameEngineTextureRenderer;
class TaskManager : public DefaultSetTex
{
public:
	static void Destroy()
	{
		if (nullptr != Inst_)
		{
			delete Inst_;
			Inst_ = nullptr;
		}
	}
public:
	// constrcuter destructer
	TaskManager();
	~TaskManager();

	// delete Function
	TaskManager(const TaskManager& _Other) = delete;
	TaskManager(TaskManager&& _Other) noexcept = delete;
	TaskManager& operator=(const TaskManager& _Other) = delete;
	TaskManager& operator=(TaskManager&& _Other) noexcept = delete;

	static TaskManager* Inst_;
	GameEngineTextureRenderer* Renderer;
	GameEngineCollision* TaskManagerMainCol;

	void StatusCheck();
	void DiffrenceCheck(int Diffrence_, float YPos,bool follower);
	void NumberSetting();
	int DiffrenceCount = 0;
	int CunrNumCount = 0;
	std::vector<int> Number;
	std::vector<int> CurNumber;

	int FollowerDiffrenceNum = 0;
	int StressDiffrenceNum = 0;
	int MentalDiffrenceNum = 0;
	int AffectionDiffrenceNum = 0;
protected:
	int CurMental = 0;
	int CurStress = 0;
	int CurAffection = 0;
	int CurFollower = 0;
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;
private:
	std::vector<CommentTextureRenderer*> Hitokoto;
	std::vector<CommentTextureRenderer*> Diffrence;
	std::vector<CommentTextureRenderer*> FollowerDiffrence;
	std::vector<CommentTextureRenderer*> CurNumberRenderer;
	bool first = false;
	std::string SoundName = "";
	bool NextCheck = true;
	bool Check = false;
	bool NumberCheck = false;
	void StatusName();
	float HitokotoTime = 0.0f;
	bool HitokotoCheck = false;
	float CheckTime = 0.0f;
};


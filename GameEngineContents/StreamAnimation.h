#pragma once
#include "DefaultSetTex.h"


// Ό³Έν :
enum class StreamContents
{
	Tutorial,
};

class StreamAnimation : public DefaultSetTex
{
public:
	// constrcuter destructer
	StreamAnimation();
	~StreamAnimation();

	// delete Function
	StreamAnimation(const StreamAnimation& _Other) = delete;
	StreamAnimation(StreamAnimation&& _Other) noexcept = delete;
	StreamAnimation& operator=(const StreamAnimation& _Other) = delete;
	StreamAnimation& operator=(StreamAnimation&& _Other) noexcept = delete;

	StreamContents Contents;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;

	bool first = true;
private:
	void ContentsUpdate(StreamContents Contents);
	void Tutorial();
	float Time = 0;
	std::map<std::string, StreamContents> ContentsMap;
};


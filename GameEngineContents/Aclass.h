#pragma once

// Ό³Έν :
class Aclass
{
public:
	// constrcuter destructer
	Aclass();
	~Aclass();

	// delete Function
	Aclass(const Aclass& _Other) = delete;
	Aclass(Aclass&& _Other) noexcept = delete;
	Aclass& operator=(const Aclass& _Other) = delete;
	Aclass& operator=(Aclass&& _Other) noexcept = delete;

protected:

private:

};


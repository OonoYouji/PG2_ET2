#pragma once

/// <summary>
/// すべてのシーン遷移に継承させる
/// 基底クラス
/// </summary>
class ITransition {
public: // member method

	// 仮想デストラクタ
	virtual ~ITransition() = default;

	// defualt method
	virtual void Init() = 0;
	virtual void Updata() = 0;
	virtual void Draw() = 0;
	virtual void Finalize() = 0;

protected: // member object

	bool isReturn_;
	bool preIsReturn_;

	bool isEnd_;

public: // accessor

	bool GetTriggerIsReturn() const { return isReturn_ && !preIsReturn_; }
	bool GetIsEnd() const { return isEnd_; }

};


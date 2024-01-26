#pragma once

#include "MyVector2.h"
#include "MyMatrix3x3.h"
#include "QuadVertex.h"
#include <string>

/// <summary>
/// すべての２次元カメラの基底クラス
/// </summary>
class ICamera {
public: // member method

	// 仮想デストラクタ
	virtual ~ICamera() = default;

	// default method
	virtual void Init() = 0;
	virtual void Updata() = 0;
	//virtual void Draw() = 0;
	virtual void Finalize() = 0;

protected:

	/*----------------------------------
		基礎変数
	----------------------------------*/

	/// STR -----
	Vec2f worldPos_;
	float theta_;
	Vec2f scale_;

	Vec2f size_;

	QuadVerf localVertex_;
	Matrix3x3 worldMatrix_;

	/// レンダリングパイプライン用
	Matrix3x3 viewMatrix_;
	Matrix3x3 orthoMatrix_;
	Matrix3x3 viewportMatrix_;


	/*----------------------------------
		その他
	----------------------------------*/

	bool isMove_;

	Vec2f preWorldPos_;
	float preTheta_;
	Vec2f preScale_;
	Vec2f preSize_;

	QuadVerf worldVertex_;


public: // user method

	/// <summary>
	/// 更新処理の最初に行うべきもの
	/// </summary>
	void BeginFrame();

	/// <summary>
	/// imguiを使用してデバッグ情報の表示と編集を行う
	/// </summary>
	/// <param name="windowName"> imguiのwindowの名前	 </param>
	/// <param name="cameraName"> treeNodeの名前		 </param>
	void ImGuiDebug(const std::string& windowName, const std::string& cameraName);


	/// <summary>
	/// isMove_がtrueのときworld,view行列の生成を行う
	/// </summary>
	void MakeMatrix();

	/// <summary>
	/// ローカル座標上の頂点からortho行列の生成を行う
	/// </summary>
	/// <param name="localVertex">ローカル座標上での各頂点</param>
	void SetOrthoMatrix(const QuadVerf& localVertex);

	/// <summary>
	/// viewport行列の生成
	/// </summary>
	/// <param name="lt">	スクリーン座標系での左上座標				</param>
	/// <param name="size">	左上座標からどれくらいの大きさで表示するか	</param>
	void SetViewportMatrix(const Vec2f& lt, const Vec2f& size);

	//// NDCの生成(一部) -----
	Matrix3x3 MakeOrthoMatrix(float top, float bottom, float left, float right) const;
	Matrix3x3 MakeViewportMatrix(float top, float left, float width, float height) const;

	/// <summary>
	/// world行列をいれるとscreen行列を返す関数
	/// </summary>
	/// <param name="worldMatrix">	world座標系				</param>
	/// <returns>					screen行列(WvpVp行列)		</returns>
	Matrix3x3 MakeWvpVpMatrix(const Matrix3x3& worldMatrix) const {
		return worldMatrix * viewMatrix_ * orthoMatrix_ * viewportMatrix_;
	}

	/// <summary>
	/// screen座標上にあるものをworld座標に変換するため、
	/// NDCを生成するための行列をすべて逆行列にし逆順に計算する
	/// </summary>
	/// <returns> worldMatrix </returns>
	Matrix3x3 Screen2WorldMatrix(void);


public:


	void SetSize(const Vec2f& size) {
		size_ = size;
	}
	Vec2f GetSize() const {
		return size_;
	}

	Vec2f GetWorldPos() const {
		return worldPos_;
	}

	QuadVerf GetWorldVertex() const {
		return worldVertex_;
	}


};


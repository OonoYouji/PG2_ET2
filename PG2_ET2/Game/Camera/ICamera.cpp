#include "ICamera.h"
#include "NovicePlus.h"

void ICamera::BeginFrame() {

	/// 前フレームと誤差があれば移動trueになる
	isMove_ = (preWorldPos_ != worldPos_)
		or (preTheta_ != theta_)
		or (preScale_ != scale_)
		or (preSize_ != size_);

	preWorldPos_ = worldPos_;
	preTheta_ = theta_;
	preScale_ = scale_;
	preSize_ = size_;

}

void ICamera::ImGuiDebug(const std::string& windowName, const std::string& cameraName) {
	windowName;
	cameraName;
#ifdef _DEBUG
	ImGui::Begin(windowName.c_str());

	if (ImGui::TreeNode(cameraName.c_str())) {

		ImGui::DragFloat2("worldPos", &worldPos_.x, 1.0f);
		ImGui::DragFloat("theta", &theta_, 0.01f);
		ImGui::DragFloat2("scale", &scale_.x, 0.01f);



		ImGui::TreePop();
	}

	ImGui::End();
#endif // _DEBUG
}

void ICamera::MakeMatrix() {
	if (!isMove_) { return; }

	worldMatrix_ = Matrix3x3::MakeAffine(scale_, theta_, worldPos_);
	viewMatrix_ = Matrix3x3::MakeInverse(worldMatrix_);

	/// フレームのようなもの
	worldVertex_ = Matrix3x3::Transform(localVertex_, worldMatrix_);

}

void ICamera::SetOrthoMatrix(const QuadVerf& localVertex) {

	/// local座標上の頂点を更新
	localVertex_ = localVertex;

	/// 行列を再生成
	orthoMatrix_ = MakeOrthoMatrix(
		localVertex_.lt.y,
		localVertex_.rb.y,
		localVertex_.lt.x,
		localVertex_.rb.x
	);
}

void ICamera::SetViewportMatrix(const Vec2f& lt, const Vec2f& size) {
	viewportMatrix_ = MakeViewportMatrix(lt.y, lt.x, size.x, size.y);
}

Matrix3x3 ICamera::MakeOrthoMatrix(float top, float bottom, float left, float right) const {
	return Matrix3x3(
		2.0f / (right - left), 0.0f, 0.0f,
		0.0f, 2.0f / (top - bottom), 0.0f,
		(left + right) / (left - right), (top + bottom) / (bottom - top), 1.0f
	);
}

Matrix3x3 ICamera::MakeViewportMatrix(float top, float left, float width, float height) const {
	return Matrix3x3(
		width / 2.0f, 0.0f, 0.0f,
		0.0f, -(height / 2.0f), 0.0f,
		left + (width / 2.0f), top + (height / 2.0f), 1.0f
	);
}

Matrix3x3 ICamera::Screen2WorldMatrix(void) {
	return Matrix3x3::MakeInverse(viewportMatrix_) * Matrix3x3::MakeInverse(orthoMatrix_) * Matrix3x3::MakeInverse(viewMatrix_); 
}



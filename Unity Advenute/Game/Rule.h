#pragma once


class Rule: public IGameObject
{
public :
	Rule();
	~Rule();
	//更新処理
	void Update();
	//描画処理
	void Render(RenderContext& rc);

private:
	//スプライトレンダー
	SpriteRender spriteRender;
	SoundSource* ruleBGM; //ルール説明のBGM。
};


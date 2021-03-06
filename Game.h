//
// Game.h
//

#pragma once

#include "StepTimer.h"

#include <PrimitiveBatch.h>
#include <VertexTypes.h>
#include <Effects.h>
#include <CommonStates.h>
#include <SimpleMath.h>
#include <Model.h>
#include <Keyboard.h>

#include"DebugCamera.h"


// A basic game implementation that creates a D3D11 device and
// provides a game loop.
class Game
{
public:

    Game();

    // Initialization and management
    void Initialize(HWND window, int width, int height);

    // Basic game loop
    void Tick();

    // Messages
    void OnActivated();
    void OnDeactivated();
    void OnSuspending();
    void OnResuming();
    void OnWindowSizeChanged(int width, int height);

    // Properties
    void GetDefaultSize( int& width, int& height ) const;

private:

    void Update(DX::StepTimer const& timer);
    void Render();

    void Clear();
    void Present();

    void CreateDevice();
    void CreateResources();

    void OnDeviceLost();

    // Device resources.
    HWND                                            m_window;
    int                                             m_outputWidth;
    int                                             m_outputHeight;

    D3D_FEATURE_LEVEL                               m_featureLevel;
    Microsoft::WRL::ComPtr<ID3D11Device>            m_d3dDevice;
    Microsoft::WRL::ComPtr<ID3D11Device1>           m_d3dDevice1;
    Microsoft::WRL::ComPtr<ID3D11DeviceContext>     m_d3dContext;
    Microsoft::WRL::ComPtr<ID3D11DeviceContext1>    m_d3dContext1;

    Microsoft::WRL::ComPtr<IDXGISwapChain>          m_swapChain;
    Microsoft::WRL::ComPtr<IDXGISwapChain1>         m_swapChain1;
    Microsoft::WRL::ComPtr<ID3D11RenderTargetView>  m_renderTargetView;
    Microsoft::WRL::ComPtr<ID3D11DepthStencilView>  m_depthStencilView;

    // Rendering loop timer.
    DX::StepTimer                                   m_timer;

	//追加したもの(引っ越し)＊
	std::unique_ptr<DirectX::PrimitiveBatch<DirectX::VertexPositionColor>> m_batch;
	std::unique_ptr<DirectX::BasicEffect> m_effect;
	Microsoft::WRL::ComPtr<ID3D11InputLayout> m_inputLayout;

	DirectX::SimpleMath::Matrix m_world;
	DirectX::SimpleMath::Matrix m_view;
	DirectX::SimpleMath::Matrix m_proj;

	//カメラ＊
	std::unique_ptr<DebugCamera> m_debugcamera;


	//エフェクトファクトリー
	std::unique_ptr<DirectX::EffectFactory> m_factory;
	std::unique_ptr<DirectX::EffectFactory> m_factory2;
	//モデル

	std::unique_ptr<DirectX::Model>m_Teapot;

	std::unique_ptr<DirectX::Model>m_Grund;

	std::unique_ptr<DirectX::Model>m_model2;
	//球モデル
	std::unique_ptr<DirectX::Model>m_robo;
	std::unique_ptr<DirectX::Model>m_ball;

	//球のワールド行列
	DirectX::SimpleMath::Matrix m_worldball[20];
	//ロール
	//DirectX::SimpleMath::Matrix rotmatx[20];
	////ヨー（方位角）
	DirectX::SimpleMath::Matrix rotmaty[20];



	//Teaポット
	DirectX::SimpleMath::Matrix t_rotmaty[20];
	DirectX::SimpleMath::Matrix t_transmat[20];
	DirectX::SimpleMath::Matrix t_scales[20];
	DirectX::SimpleMath::Matrix t_matome[20];
	DirectX::SimpleMath::Matrix t_scale;

	DirectX::SimpleMath::Matrix transmats;



	float maware=0;
	float avleg = 0;
	float f_scale = 0;

	//自機系統
	std::unique_ptr<DirectX::Keyboard> keyboard;
	DirectX::SimpleMath::Vector3 tank_pos;
	DirectX::SimpleMath::Matrix t_tank_world;
	float tank_angle;
};
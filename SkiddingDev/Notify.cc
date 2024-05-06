--[[
src code (enjoy)
]]



local TweenService = game:GetService("TweenService")

local notify = {}

function notify.notify(text)
	local notificationGui = Instance.new("ScreenGui")
	notificationGui.ZIndexBehavior = Enum.ZIndexBehavior.Sibling

	local notificationFrame = Instance.new("Frame")
	notificationFrame.Name = "Notification"
	notificationFrame.Parent = notificationGui
	notificationFrame.BackgroundColor3 = Color3.fromRGB(255, 255, 255)
	notificationFrame.BorderColor3 = Color3.fromRGB(0, 0, 0)
	notificationFrame.BorderSizePixel = 0
	notificationFrame.Size = UDim2.new(0, 190, 0, 98)

	local corner = Instance.new("UICorner")
	corner.CornerRadius = UDim.new(0, 5)
	corner.Parent = notificationFrame

	local gradient = Instance.new("UIGradient")
	gradient.Color = ColorSequence.new{
		ColorSequenceKeypoint.new(0.00, Color3.fromRGB(0, 0, 0)),
		ColorSequenceKeypoint.new(0.02, Color3.fromRGB(0, 0, 0)),
		ColorSequenceKeypoint.new(0.04, Color3.fromRGB(0, 0, 0)),
		ColorSequenceKeypoint.new(0.15, Color3.fromRGB(0, 0, 0)),
		ColorSequenceKeypoint.new(0.49, Color3.fromRGB(0, 0, 0)),
		ColorSequenceKeypoint.new(0.84, Color3.fromRGB(0, 0, 0)),
		ColorSequenceKeypoint.new(0.99, Color3.fromRGB(0, 0, 0)),
		ColorSequenceKeypoint.new(1.00, Color3.fromRGB(0, 0, 0))
	}
	gradient.Parent = notificationFrame

	local textLabel = Instance.new("TextLabel")
	textLabel.Parent = notificationFrame
	textLabel.BackgroundTransparency = 1
	textLabel.Position = UDim2.new(0, 0, 0, 0)
	textLabel.Size = UDim2.new(1, 0, 1, 0)
	textLabel.Font = Enum.Font.GothamBold
	textLabel.Text = text
	textLabel.TextColor3 = Color3.new(1, 1, 1)
	textLabel.TextScaled = true
	textLabel.TextSize = 14
	textLabel.TextWrapped = true

	notificationGui.Parent = game.Players.LocalPlayer:WaitForChild("PlayerGui")

	notificationFrame.Position = UDim2.new(1, 0, 1, 0)
	local slideInTween = TweenService:Create(notificationFrame, TweenInfo.new(1, Enum.EasingStyle.Quad, Enum.EasingDirection.Out), {Position = UDim2.new(1, -200, 1, -150)})
	slideInTween:Play()


	coroutine.wrap(function()
		wait(5)
		local slideOutTween = TweenService:Create(notificationFrame, TweenInfo.new(1, Enum.EasingStyle.Quad, Enum.EasingDirection.In), {Position = UDim2.new(1, 0, 1, 0)})
		slideOutTween:Play()
		wait(1)
		notificationGui:Destroy()
	end)()
end

return notify

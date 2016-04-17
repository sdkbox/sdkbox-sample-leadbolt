
local MainScene = class("MainScene", cc.load("mvc").ViewBase)

function MainScene:onCreate()
    print("Sample Startup")

    local label = cc.Label:createWithSystemFont("QUIT", "sans", 32)
    local quit = cc.MenuItemLabel:create(label)
    quit:onClicked(function()
        os.exit(0)
    end)
    local size = label:getContentSize()
    local menu = cc.Menu:create(quit)
    menu:setPosition(display.right - size.width / 2 - 16, display.bottom + size.height / 2 + 16)
    self:addChild(menu)

    self:setupTestMenu()
end

function MainScene:setupTestMenu()
    sdkbox.PluginLeadBolt:init()
    sdkbox.PluginLeadBolt:setListener(function(args)
        dump(args)
    end)

    sdkbox.PluginLeadBolt:loadModuleToCache("inapp")

    local menu = cc.Menu:create()

    local label1 = cc.Label:createWithSystemFont("show ad", "sans", 28)
    local item1 = cc.MenuItemLabel:create(label1)
    item1:onClicked(function()
        print("show ad")
        if sdkbox.PluginLeadBolt:isAdReady('inapp') then
            sdkbox.PluginLeadBolt:loadModule('inapp')
        else
            print('leadbolt ad is not ready')
        end
    end)
    menu:addChild(item1)

    menu:alignItemsVerticallyWithPadding(24)
    self:addChild(menu)
end

return MainScene

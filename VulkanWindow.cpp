#include "VulkanWindow.h"
#include "RenderWindow.h"
#include <QKeyEvent>

VulkanWindow::VulkanWindow()
{  }

QVulkanWindowRenderer* VulkanWindow::createRenderer()
{
    //Makes a new instance of the RenderWindow (our Renderer) class
    return mRenderWindow = new RenderWindow(this, true); // last true == try MSAA
}

void VulkanWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_D)
    {
        qDebug("I pressed the D button");
        dynamic_cast<RenderWindow*>(mRenderWindow)->mMeshes.at(3)->move(-0.1f);
    }
    if(event->key() == Qt::Key_A)
    {
        qDebug("I pressed the A button");

        dynamic_cast<RenderWindow*>(mRenderWindow)->mMeshes.at(3)->move(0.1f);
    }
    if (event->key() == Qt::Key_W)
    {
        qDebug("I pressed the W button");

        dynamic_cast<RenderWindow*>(mRenderWindow)->mMeshes.at(3)->move(0.f,0.f,0.1f);
    }
    if (event->key() == Qt::Key_S)
    {
        qDebug("I pressed the S button");

        dynamic_cast<RenderWindow*>(mRenderWindow)->mMeshes.at(3)->move(0.f,0.f,-0.1f);
    }
    if (event->key() == Qt::Key_Escape)
    {
        QCoreApplication::quit();       //Shuts down the whole program
    }
}

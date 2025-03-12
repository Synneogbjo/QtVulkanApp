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
    if (event->key() == Qt::Key_W) mInput.W = true;
    if(event->key() == Qt::Key_A) mInput.A = true;
    if (event->key() == Qt::Key_S) mInput.S = true;
    if (event->key() == Qt::Key_D) mInput.D = true;

    if (event->key() == Qt::Key_Escape) mInput.ESCAPE = true;

}

void VulkanWindow::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_W) mInput.W = false;
    if(event->key() == Qt::Key_A) mInput.A = false;
    if (event->key() == Qt::Key_S) mInput.S = false;
    if (event->key() == Qt::Key_D) mInput.D = false;

    if (event->key() == Qt::Key_Escape) mInput.ESCAPE = false;
}

void VulkanWindow::SolveInput()
{
    auto rw = dynamic_cast<RenderWindow*>(mRenderWindow);

    bool bRender = (rw) ? !rw->GetHasLost() : false;

    if (mInput.W && bRender)
    {
        rw->mMeshes.at(2)->move(0.f,0.f,0.04f);
    }
    if (mInput.A && bRender)
    {
        rw->mMeshes.at(2)->move(0.04f);
    }
    if (mInput.S && bRender)
    {
        rw->mMeshes.at(2)->move(0.f,0.f,-0.04f);
    }
    if (mInput.D && bRender)
    {
        rw->mMeshes.at(2)->move(-0.04f);
    }
    if (mInput.ESCAPE)
    {
        QCoreApplication::quit();
    }
}

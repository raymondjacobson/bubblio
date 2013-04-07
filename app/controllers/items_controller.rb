class ItemsController < ApplicationController
  before_filter :bubble_owns_item

  def index
  end

  def new
  	@item = @bubble.items.new
  end

  def show
  	@item = @bubble.items.find(params[:id])
  end

  def create
  	@item = @bubble.items.new(:file => params[:item])
  	if @item.save
      flash[:success] = "Item uploaded!"
      redirect_to :back
    else
      render 'new'
    end
  end

  def destroy
    @item = @bubble.items.find(params[:id])
    @item.destroy
    redirect_to :back
  end
end

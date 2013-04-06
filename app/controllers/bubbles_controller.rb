class BubblesController < ApplicationController
  def new
  	@bubble = Bubble.new
  end

  def show
  	@bubble = Bubble.find(params[:id])
    @items = @bubble.items.order("happened_at DESC")
    @links = @bubble.links.order("happened_at DESC")
  end

  def create
  	@bubble = Bubble.new(params[:bubble])
  	if @bubble.save
      flash[:success] = "Bubble created!"
      redirect_to bubble_path(@bubble)
    else
      render 'new'
    end
  end

  def destroy
    @bubble = Bubble.find(params[:id])
    @bubble.destroy
    redirect_to root_path
  end

end
